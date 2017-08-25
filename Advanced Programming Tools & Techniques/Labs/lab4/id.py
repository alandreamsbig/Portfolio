#!/user/bin/python

import sys

file = open( sys.argv[1], "r" )
line = file.readline()

dictionary = dict()

while line:
		split_id = line.split(' ',1)
		dictionary[split_id[0]] = split_id[1]
		line = file.readline()

data = dictionary.keys()
data.sort(key=int)

for key in data:
		print key, dictionary[key].rstrip()
