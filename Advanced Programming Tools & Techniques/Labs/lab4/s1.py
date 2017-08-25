#!/user/bin/python

import sys

file = open( sys.argv[1], "r" )
line = file.readline()


for data in file :
	line = data.split()
		
	y = 0
	for i in line[1:]:
		y = y + int(i)
		
	print line[0], " ", str(y/len(line)-1)


