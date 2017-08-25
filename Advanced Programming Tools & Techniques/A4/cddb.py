#!/usr/bin/python

#author: Alan Tsai
#date: June-06-2016
#Program features: Read in sample.db, list artists, ablum date and
#name, songs. Add albums and delete albums. Help menu

import sys
import os

file = open("sample.db", 'r') #open file for reading
lines = file.readlines()


cddb = {} #create a cddb dictionary
iLines = iter(lines)
for i in iLines: #read the file line by line
	if i  == '\n':
		 continue
	artist = i.strip()
	if artist not in cddb: 
		cddb [artist] = [] #create artist as key 
	Albums = {} #create another list of Albums
	i = iLines.next() 
	 
	year = i[:4] #store the album date value 
	aname = i[5:] #store the album name value
	
	Albums["year"] = int(year) #create keys for the list of dictionary
	Albums["album"] = aname.strip()
	Albums["songs"] = []

	while i.strip() != '':
		try:
			i = iLines.next()
		except StopIteration:
			break;
		Albums["songs"].append(i.strip())
	cddb[artist].append(Albums)

#Function taking care of command input
def commandInput(): 
	selected = str(sys.argv[1])
	if selected=="-l":
		ListArtist()
	elif selected =="-d":
		DeleteAlbum()
	elif selected =="-a":
		AddAlbum()	
	elif selected =="-h":
		HelpMenu()
	else:
		print "Incorrect command command input, please check the Help Menu -h"
		return 0

#Function for taking care of -l command features
def ListArtist():
	artist = cddb.keys() #get the artist keys
	for i in range (len(artist)): 
		print i+1,":", artist[i] #list all the artists
	print "q : quit"
	print "\n"
	
	#user input
	artistChoice = raw_input("Please select a number for the artist or enter ""q"" to quit: ")
	
	if artistChoice =="q":
		return 0
	else:
		for j in range (len(cddb[artist[int(artistChoice)-1]])):
			album = cddb[artist[int(artistChoice)-1]][j] #get the album data
			print	j+1,":", album["year"], album["album"] #print the values
		print "a : return"
		print "\n"
	
		albumChoice = raw_input("Please select a number for the album or enter ""a"" to return: ")	
		
		if albumChoice =="a":	
				ListArtist()		
		else:
			songs = cddb[artist[int(artistChoice)-1]][int(albumChoice)-1] 
			for x in songs["songs"]: #getting the songs from the dictionary
				print x
			print"\n"
			print "a : return"
		print "\n"
		
		goBack = raw_input("Please select the letter ""a"" to return to the menu: ")
		
		if goBack=="a":
				ListArtist() 		

#Function for the -a features
def AddAlbum():
	print "To add an Album, please enter the artist, release date, album name, and track list"
	artistInput = raw_input("Artist: ") #takecare of user inputs
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
		trackList += "%s\n" % line #take song input as a list of strings
	print "Track List: ","\n", trackList

	with open("sample.db", "a") as myfile: #open file and write to file
		myfile.write("\n")
		myfile.write(artistInput)
		myfile.write("\n")
		myfile.write(albumDate + " " + albumName)
		myfile.write("\n")
		myfile.write(trackList)
	
	print "The album: ",albumName,"has been added"	

#Function for the -d features		
def DeleteAlbum():
	artist = cddb.keys() #List artists
	for i in range (len(artist)):
		print i+1,":", artist[i]
	print "q : quit"

	artistChoice = raw_input("Please select a number for the artist for an album or enter ""q"" to quit: ")

	if artistChoice =="q":
		return 0
	else:
		for j in range (len(cddb[artist[int(artistChoice)-1]])):
			album = cddb[artist[int(artistChoice)-1]][j] #list albums to delete
			print j+1,":", album["year"], album["album"]
		print "a : return"

	albumChoice = raw_input("Please select a number for the album or enter ""a"" to return: ")
	
	#get the album to delete
	userSelected = cddb[artist[int(artistChoice)-1]][int(albumChoice)-1]["album"]
	song = cddb[artist[int(artistChoice)-1]][int(albumChoice)-1]
	songDelete = song["songs"][-2] #get the song value delimeter for delete
	songDelete2 = song["songs"][0]
	artistSelected = cddb.keys() #get the artist delimeter for delete
	artistRemove = artistSelected[int(artistChoice)-1]
	
	flag = 1
	with open("sample.db") as oldfile: #deletes the artist to the album name
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
	with open("sample2.db") as oldfile2: #deletes the first song to last song
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
	os.rename("sample3.db", "sample.db") #rename file
	
	print "The album: ",userSelected, "has been deleted"

#Fuction for the -h features
def HelpMenu():
	print "\n"
	print "This program reads in a file called sample.db"
	print "The features of this program include listing and selecting "
	print "artists, albums, and songs. Adding new albums and deleting albums"
	print "\n" 
	print "   ---------------- CDDB Help Menu-----------------"
	print "The following commands can be used to call the feature"
	print "\n"
	print " -l  Display a list of artists, the list album release date and "
	print "     names, allow the user to choose an album by # or return to "
	print "     the menu above. If an album is entered, list all songs in "
	print "     that album."
	print "\n"
	print " -d  Delete album. Similar to above, display menus and choose "
	print "     album to delete"
	print "\n"
	print " -a  Add album. User prompt for artist, album release date and "
	print "     year. And finally the track list"
	print "\n"
	print " -h  Help menu"
	print "\n"

commandInput()	


