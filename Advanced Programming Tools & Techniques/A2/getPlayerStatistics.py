#!/usr/bin/python

# Reads sample.in as default, if there is no filename, let the user input it
import sys
if len( sys.argv ) < 2 :
   fileName = "sample.in"
else :
   fileName = sys.argv[1]
file_ = open(fileName, "r")

BaseballData = {}                
teamList = []                      
#l = file_.readline()

#While reading the file, split the csv values and store them to BaseballData
#and store the team list to teamList

for l in file_:
   l = l.rstrip()
   localList = []
   fieldCount = 0
   for field in l.split(",") :
       if (fieldCount == 2) :
           key = field
           if not (BaseballData.has_key(key)) :
               #BaseballData[key] = key
               BaseballData[key] = []
               teamList.append(key)
       else :      
           localList.append(field)
       fieldCount += 1
   BaseballData[key].append(localList)

# sorts the teamList and displays it with numbered options
teamList.sort()
input = True      

while input :
   number = 1
   print "\n---TEAM MENU OPTIONS---"
   for i in teamList :
       print(str(number) +": " + i)
       number += 1

   print "6: Quit"
    
   prompt = raw_input("\nEnter the number of the team to display the players: ")
   selectedTeamNum = int(prompt)

   if (selectedTeamNum == 6) :
       input = False
       sys.exit
   else :
		selectedTeamName = teamList[selectedTeamNum-1]
		p = 1
		for player in BaseballData[selectedTeamName]:
			print(str(p) + ": " + player[0] + ", " + player[1])
			p = p + 1
		
		i = 1
		for stats in BaseballData[selectedTeamName]:
			statistic = BaseballData[selectedTeamName][0][2:]			
			print("\n")		
			print("Position: " + statistic[0])
			print("At Bats: " + statistic[1])
			print("Base Hits: " + statistic[2])
			print("Doubles: " + statistic[3])
			print("Triples: " + statistic[4])
			print("Home Runs: " + statistic[5])
			print("RBIs: " + statistic[6])
			print("Batting Average: " + statistic[7])	
			i = i+1

		Return = raw_input( "\nEnter 6 to return to Teams list: ")
		Menu = int(Return)
