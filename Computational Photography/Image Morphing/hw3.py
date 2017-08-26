#!/usr/bin/env python
import os
import shutil
import sys
import argparse

import numpy as np
from scipy.misc import imread, imsave
from scipy.spatial import Delaunay

#########################################
###########    Skeleton    ##############
#########################################

def intermediate_points(pts1, pts2, fraction):
    """Computes the intermediate point set for a given set of correspondence
    points.  fraction represents the relative weight on start vs end frames, a
    number in the interval [0,1]. 0 means only use the first points, 1 means
    only use the second points.

    The intermediate point set is a linear interpolation of the start and end
    point sets."""

    # Compute and return the intermediate point set.
    intermediatePoints = pts1 + fraction * (pts2 - pts1)
    return intermediatePoints

def blend(img1, img2, fraction):
    """Blend between img1 and img2 based on the given fraction."""
    # Compute and return the blended image.
    blendedImage = (1-fraction) * img1 + fraction * img2
    return blendedImage

def barycentric(points, query):
    """Compute the barycentric coordinates for a query point within the given
    triangle points."""
    # Form the matrix A containing the triangle points and 1s in the proper
    # positions.
    A = np.array([points[0,:,0],points[0,:,1],[1,1,1]])
    # Create the vector b containing the query coordinates as well as a 1.
    b = np.array([[query[0]],[query[1]],[1]])
    # Solve the linear system Ax = b for the barycentric coordinates x.
    # HINT: Look at numpy.linalg.solve.
    barycentricCoor = np.linalg.solve(A,b)

    return barycentricCoor

def bilinear_interp(image, point):
    """Perform bilinearly-interpolated color lookup in a given image at a given point."""
    """Reference:https://rosettacode.org/wiki/Bilinear_interpolation#Python"""
    bilinear = []
    # Compute the four integer corner coordinates for interpolation.
    modXi = int(point[0])
    modYi = int(point[1])
    modXf = point[0] - modXi
    modYf = point[1] - modYi
    
    # Compute the fractional part of the point coordinates.
    modXiPlusOneLim = min(modXi+1,image.shape[1]-1)
    modYiPlusOneLim = min(modYi+1,image.shape[0]-1)

    for i in range(image.shape[2]):
        bl = image[modYi, modXi, i]
        br = image[modYi, modXiPlusOneLim, i]
        tl = image[modYiPlusOneLim, modXi, i]
        tr = image[modYiPlusOneLim, modXiPlusOneLim, i]
   
    # Interpolate between the top two pixels.
        t = modXf * tr + (1. - modXf) * tl
    # Interpolate between the bottom two pixels.
        b = modXf * br + (1. - modXf) * bl
    # Return the result of the final interpolation between top and bottom.
    pxf = modYf * t + (1. - modYf) * b
    bilinear.append(int(pxf+0.5))
    return bilinear

def warp(source, source_points, dest_triangulation):
    """Warp the source image so that its correspondences match the destination
    triangulation."""
    result = np.zeros_like(source)

    # Fill in the pixels of the result image.

    # NOTE: This can be done much more efficiently in Python using a series of
    # numpy array operations as opposed to a for loop.

    # HINTS for fast version:
    # * Delaunay.find_simplex can take a list / array of points and look
    #   them up all at once.
    # * You can modify your bilinear_interp() and barycentric() functions to
    #   take arrays of points instead of single points. Express the actions in
    #   these functions via array operations.
    # * Look up numpy.mgrid / meshgrid for tips on how to quickly generate an
    #   array containing all of the points in an image of size [R,C].

    for r in range(result.shape[0]):
        for c in range(result.shape[1]):
            # Find the triangle index (look at Delaunay.find_simplex) for the
            # current point in the destination triangulation, then use it to
            # get the points of the destination triangle.
            currPixel = np.array([r,c])
            triIndex = dest_triangulation.find_simplex(source_points)
            #print triIndex
            #triSimplex = dest_triangulation.simplices[triIndex]
            #print triSimplex
            #points = dest_triangulation.points[triSimplex]
            # Get the indices for the points of the destination triangle
            # (Delaunay.simplices) and use them to get the corresponding points
            # for the source triangle.
            corrPoint = source_points[dest_triangulation.simplices[triIndex]]
            # Compute the barycentric coordinates for the current destination
            # point using the destination triangle's points.
            query = np.array([r,c])
            barryCoor = barycentric(corrPoint,query)
            # Compute the sum of the source points weighted by the barycentric
            # coordinates from the destination triangle
            warpPts = barryCoor[0]*corrPoint[0] + barryCoor[1]*corrPoint[1]+barryCoor[2]*corrPoint[2] 
            # Get the resulting color from the source image via bilinear
            # interpolation, and place it in the result image.
            result[r, c] = 0 #bilinear_interp(source, warpPts)
    return result

def morph(img1, img2, pts1, pts2, fraction, debug):
    """Computes the intermediate morph of the given fraciton between img1
    and img2 using their correspondences."""

    # Compute the intermediate points between the points of the first and
    # second triangulations according to the warp fraction.
    intermediate_pts = intermediate_points(pts1,pts2,fraction) 
    if (debug):
        print "intermediate_pts = \n" + str(intermediate_pts)

    # Compute the triangulation for the intermediate points.
    intermediate_triang = Delaunay(intermediate_pts) 
    if (debug):
        print "intermediate_triang simplices = \n" + str(intermediate_triang.simplices)

    # Warp the first image to the intermediate triangulation.
    warp1 = warp(img1,pts1,intermediate_triang)
    if (debug):
        imsave("debug/warp1_%f.png" % fraction, warp1)
        

    # Warp the second image to the intermediate triangulation.
    warp2 = warp(img2,pts2,intermediate_triang)
    if (debug):
        imsave("debug/warp2_%f.png" % fraction, warp2)

    # Blend the two warped images according to the warp fraction.
    result = blend(warp1,warp2, fraction)
    if (debug):
        imsave("debug/result_%f.png" % fraction, result)

    return result

#########################################
#####    Utility Code      ##############
#########################################

def morph_sequence(start_img, end_img, corrs, n_frames, debug):
    """Computes the n_frames long sequence of intermediate images for the warp
    between start_img and end_img, using the given correspondences in corrs."""

    start_pts, end_pts = corrs

    morph_frames = []
    for frame in range(1, n_frames-1):
        print("Computing intermediate frame %d..." % frame)
        progress = frame/(n_frames-1.)

        intermediate_frame = morph(
                start_img, end_img,
                start_pts, end_pts,
                progress,
                debug)
    
        imsave("frames/%d.png" % frame, intermediate_frame)
        morph_frames.append( intermediate_frame)

    return [start_img] + morph_frames + [end_img]

def read_corrs(fn):
    pts1 = []
    pts2 = []
    try:
        for line in open(fn).readlines():
            x1, y1, x2, y2 = [int(i) for i in line.strip().split()]
            pts1.append((x1, y1))
            pts2.append((x2, y2))
    except:
        return None

    return (np.array(pts1), np.array(pts2))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
            description = "CS435 Project 3: Morph one image into another.",
            formatter_class = argparse.ArgumentDefaultsHelpFormatter
            )

    parser.add_argument("start_fn", metavar="START_IMG", type=str, help="Filename for the start image.")
    parser.add_argument("end_fn", metavar="END_IMG", type=str, help="Filename for the end image.")
    parser.add_argument("corrs_file", metavar="CORRS_FILE", type=str, help="Text file with corresponding points. Four integers per line separated by spaces: X1 Y1 X2 Y2.")
    parser.add_argument("--n_frames", metavar="N_FRAMES", type=int, default=10, required=False, help="Number of intermediate frames to compute in the morph.")
    parser.add_argument("--outfile", metavar="OUTPUT_FILE", type=str, default="morph.mp4", required=False, help="Name of the file to save the morph movie as. Must end in .mp4")
    parser.add_argument('--debug', action='store_true', help="print debug data")

    args = parser.parse_args()

    if not args.outfile.endswith(".mp4"):
        print("Output filename must end with mp4.")
        exit(1)

    try:
        start_img = imread(args.start_fn)
        start_img = np.dstack(3*[start_img]) if start_img.ndim == 2 else start_img[:, :, :3]
    except:
        print("Error reading start image.")
        exit(1)

    try:
        end_img = imread(args.end_fn)
        end_img = np.dstack(3*[end_img]) if end_img.ndim == 2 else end_img[:, :, :3]
    except:
        print("Error reading end image.")
        exit(1)

    if start_img.shape != end_img.shape:
        print("Start and end images must be the same shape.")
        exit(1)

    corrs = read_corrs(args.corrs_file)
    if corrs is None:
        print("Error reading correspondences file.")
        exit(1)

    # Swap X/Y for Numpy Y/X (Row/Col)
    corrs = [c[:, ::-1] for c in corrs]

    # Add in the 4 corner points of the image to each correspondence set (for
    # triangulation purposes).
    nr, nc = start_img.shape[:2]
    nr -= 1; nc -= 1
    corrs[0] = np.vstack([[[0,0],[nr,0],[0,nc],[nr,nc]], corrs[0]])
    corrs[1] = np.vstack([[[0,0],[nr,0],[0,nc],[nr,nc]], corrs[1]])

    start_img = start_img.astype(np.float32) / start_img.max()
    end_img = end_img.astype(np.float32) / end_img.max()
    
    if not os.path.exists("frames"):
        os.mkdir("frames")
    if args.debug and not os.path.exists("debug"):
        os.mkdir("debug")

    morph_img_sequence = morph_sequence(start_img, end_img, corrs, args.n_frames, args.debug)

    try:
        converter = "avconv" if (os.system("which avconv") == 0) else "ffmpeg"
        codec = "h264" if (os.system("%s -codecs | grep EV | grep h264" % converter) == 0) else "mpeg4 -b 1024k"
        os.system("%s -framerate 15 -i frames/%%d.png -c:v %s -r 30 -pix_fmt yuv420p %s" % (converter, codec, args.outfile))
    except:
        print("Error converting frames to movie.")
        exit(1)
