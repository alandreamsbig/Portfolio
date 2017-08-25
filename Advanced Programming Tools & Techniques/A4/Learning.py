#!/usr/bin/python

import sys


class Album(object):
	def __init__(self,year,name,songs):
		self.year = None
		self.name = None
		self.songs = []

file = open("sample.db", 'r')
lines = file.readlines()


cddb = {}
album = Album(None,None,[])

iLines = iter(lines)
for i in iLines:
	if i  == '\n':
		 continue
	artist = i.strip()
	if artist not in cddb: 
		cddb [artist] = []
	
	album = Album(None,None,[])
	i = iLines.next()
	
	year = i[:4]
	aname = i[5:]
	album.year = int(year)
	album.name = aname

	while i.strip() != '':
		try:
			i = iLines.next()
		except StopIteration:
			break;
		album.songs.append(i.strip())
	cddb[artist].append(album)


def commandInput():
	print "Select the following artists"
	selected = str(sys.argv[1])
	if selected=="-l":
		ListAlbum()
	elif selected =="-d":
		DeleteAlbum()

	




	
def ListAlbum():
	i = 0
	artist_array = []
	for key in sorted(cddb.keys()):
		i += 1
		print str(i) + ": " + key
		artist_array.append(key)
		
#when they want to select, artist = artist_array.Index(userinput-1)
	
	artistChoice = raw_input("Please select a number for the artist or enter ""q"" to quit ")
	
	if artistChoice =="q":
		return 0
	else:
		for art,vals in cddb.iteritems():
			print art
			for alb in vals:
				#print alb.name.strip(),
				print alb.year
				#print alb.songs
	
"""		
def DeleteAlbum():
	for artist in sorted(cddb.key()):
		print artist

	artistChoice = raw_input("Please select an artist to delete album")
	if artistChoice=="1":
		print "haha"

def AddAlbum():

def Help():

def tempCDDB():
	tempfile = open("tempfile.db", 'w')	
	tempfile.write("Teseting123")
	tempfile.close()
"""
commandInput()	


