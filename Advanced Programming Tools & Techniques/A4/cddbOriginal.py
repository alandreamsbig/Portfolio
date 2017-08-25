#!/usr/bin/python

import sys
import os

file = open("sample.db", 'r')
lines = file.readlines()


cddb = {}
iLines = iter(lines)
for i in iLines:
	if i  == '\n':
		 continue
	artist = i.strip()
	if artist not in cddb: 
		cddb [artist] = []
	Albums = {}
	i = iLines.next()
	
	year = i[:4]
	aname = i[5:]
	
	Albums["year"] = int(year)
	Albums["album"] = aname.strip()
	Albums["songs"] = []

	while i.strip() != '':
		try:
			i = iLines.next()
		except StopIteration:
			break;
		Albums["songs"].append(i.strip())
	cddb[artist].append(Albums)

def commandInput():
	selected = str(sys.argv[1])
	if selected=="-l":
		ListArtist()
	elif selected =="-d":
		DeleteAlbum()
	elif selected =="-a":
		AddAlbum()	
	

def ListArtist():
	artist = cddb.keys()
	for i in range (len(artist)): 
		print i+1,":", artist[i]
	print "q : quit"
	
	artistChoice = raw_input("Please select a number for the artist or enter ""q"" to quit: ")
	
	if artistChoice =="q":
		return 0
	else:
		for j in range (len(cddb[artist[int(artistChoice)-1]])):
			album = cddb[artist[int(artistChoice)-1]][j]
			print	j+1,":", album["year"], album["album"]
		print "a : return"
		
		albumChoice = raw_input("Please select a number for the album or enter ""a"" to return: ")	
		
		if albumChoice =="a":	
				ListArtist()		
		else:
			songs = cddb[artist[int(artistChoice)-1]][int(albumChoice)-1]
			for x in songs["songs"]:
				print x
		
		goBack = raw_input("Please select the letter ""a"" to return to the menu: ")
		
		if goBack=="a":
				ListArtist() 		


def AddAlbum():
	print "To add an Album, please enter the artist, release date, album name, and track list"
	artistInput = raw_input("Artist: ")
	albumDate = raw_input("Album Year: ")
	albumName = raw_input("Album Name: ")
	print "\n"
	print "Please enter the songs in the correct format, press ENTER when you are done"
	trackList = ""
	stop = ""
	while True:
		line = raw_input()
		if line.strip() == stop:
			break
		trackList += "%s\n" % line
	print "Track List: ","\n", trackList

	with open("sample.db", "a") as myfile:
		myfile.write("\n")
		myfile.write(artistInput)
		myfile.write("\n")
		myfile.write(albumDate + " " + albumName)
		myfile.write("\n")
		myfile.write(trackList)
		myfile.write("\n")
	
		
def DeleteAlbum():
	artist = cddb.keys()
	for i in range (len(artist)):
		print i+1,":", artist[i]
	print "q : quit"

	artistChoice = raw_input("Please select a number for the artist for an album or enter ""q"" to quit: ")

	if artistChoice =="q":
		return 0
	else:
		for j in range (len(cddb[artist[int(artistChoice)-1]])):
			album = cddb[artist[int(artistChoice)-1]][j]
			print j+1,":", album["year"], album["album"]
		print "a : return"

	albumChoice = raw_input("Please select a number for the album or enter ""a"" to return: ")
	
	userSelected = cddb[artist[int(artistChoice)-1]][int(albumChoice)-1]["album"]
	song = cddb[artist[int(artistChoice)-1]][int(albumChoice)-1]
	songDelete = song["songs"][-1]
	songDelete2 = song["songs"][0]
	artistSelected = cddb.keys()
	artistRemove = artistSelected[int(artistChoice)-1]

	flag = 1
	with open("sample.db") as oldfile:
		with open("sample2.db","w") as newfile:
			for line in oldfile:
				if flag:
					if artistRemove in line:
						flag = 0
					else:
						newfile.write(line)
				elif userSelected in line:
						flag = 1  

	flag2 = 1
	with open("sample2.db") as oldfile2:
		with open("sample3.db","w") as newfile2:
			for line2 in oldfile2:
				if flag2:
					if songDelete2 in line2:
						flag2 = 0
					else:
						newfile2.write(line2)
				elif songDelete in line2:
					flag2 = 1
	os.remove("sample2.db")	
	os.rename("sample3.db", "sample.db")
	
	print "The album: ",userSelected, "has been deleted"

#def Help():


commandInput()	


