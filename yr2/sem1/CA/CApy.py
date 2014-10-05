#modules for ordering a dictionary and url requests
from collections import OrderedDict
import urllib.request

#Record Legend - refer to here to check output breakdown
"""
rec[0]  --  Age
rec[1]  --  workclass
rec[2]  --  fnlwgt (unused)
rec[3]  --  education (unused)
rec[4]  --  education number
rec[5]  --  marital status
rec[6]  --  occupation
rec[7]  --  relationship
rec[8]  --  race
rec[9]  --  sex
rec[10] --  capital gain
rec[11] --  capital loss
rec[12] --  Hours/week
rec[13] --  native country (unused)
rec[14] --  outcome
"""

#check if a string represents an int
#useful for seperating different type elements in a list
def isInt(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False #in this program, this'll mean it's a dict


#find total number of records
def tallyRecs(file):
    f.seek(0,0)
    print("counting records")

    i=0
    for row in file:
        if(len(row)>1):
            i+=1
            
    f.seek(0,0)    
    return i

#tally up raw data into up/down-list depending on $income (ie. training)
def doRecs(tList,rec):
        for i in range(0,13):            
            if i==2 or i==3: continue #ignore unwanted attributes

            if isInt(rec[i]): #i.e if element is not a dict
                tList[i] += (int)(rec[i])
            else:
                if rec[i] in tList[i]:
                    tList[i][rec[i]] += 1
                else:
                    tList[i][rec[i]] = 1

        return 1 #to increment up/down accordingly


#taking raw records data and averaging into the classifier list           
def avrRecs(dList,uList,dN,uN):
    avrList=[0,{},0,{},0,{},{},{},{},{},0,0,0]
    
    for i in range(0,13):
        if i==2 or i==3: continue

        if type(avrList[i]) is not dict:
            #average up/down values of same integer key
            avrList[i] = ((int)((((uList[i]/uN)+(dList[i]/dN))/2)*1000)/1000)
        else:
            #run through dicts for up/down, averaging as we go
            for dKey,dVal in dList[i].items():
                for uKey,uVal in uList[i].items():
                    if dKey==uKey:    
                        if dVal/dN >= uVal/uN:
                            avrList[i][dKey]=-1 #mark as bad attribute
                        else:
                            avrList[i][dKey]=1 #mark as good attribute
    return avrList

#checking new records against classifier,to tally up outcome (ie. testing)
def checkRec(tList,rec):
    tally=0
    #tally is: +1 for good attr, -1 for bad attr, total is the result
    #result tells if there is more bad than good and vice versa
    for i in range(0,13):
        if i==2 or i==3: continue

        if type(tList[i]) is not dict:
            if (int)(rec[i]) > tList[i]:
                tally+=1
            else:
                tally-=1
        else:    
            if rec[i] in tList:
                tally += tList[rec[i]]
        #after this we have a resulting tally, which is essentially
        #our educated guess, based on the classifier

    #here we check if we guessed correctly
    if rec[14] == "<=50K":
        return (tally <= 0)
    else:
        return not (tally <= 0)
     
#read from url       
URL="http://archive.ics.uci.edu/ml/\
machine-learning-databases/adult/adult.data"
print("Url requesting...")

local,headers=urllib.request.urlretrieve(URL)

f=open(local,'r')        


#using two lists: some values are stored as ints, others as dicts
downList=[0,{},0,{},0,{},{},{},{},{},0,0,0]
upList=[0,{},0,{},0,{},{},{},{},{},0,0,0]
    
totalRecs=tallyRecs(f)
accur,over,under,no=0,0,0,0


for row in f:
    if under+over >= totalRecs*0.75: break # use 75% of file for training
    
    if len(row) <= 1: continue
    part=row.strip("\n").split(", ") #turn data into list for processing
    
    if part[14] == "<=50K":
        under+=doRecs(downList,part)
    else:   
        over+=doRecs(upList,part)


#printing out all elements of down-list (refer to legend up top)
print("\ndownList:\n----------")
for i in  range(0,13):
    if i==2 or i==3: continue
    if type(downList[i]) is dict:
        for key,value in downList[i].items():
            print(key,value/under)
    else:
        print (downList[i]/under)
    print("")


#printing out all elements of up-list
print("\nupList:\n----------")
for i in  range(0,13):
    if i==2 or i==3: continue
    if type(upList[i]) is dict:
        for key,value in upList[i].items():
            print(key,value/over)
    else:
        print (upList[i]/over)
    print("")
    

clasList=avrRecs(downList,upList,under,over) #creating classifier


#printing out all elements of average-list
print("\navrList:\n----------")
for i in  range(0,13):
    if i==2 or i==3: continue
    if type(clasList[i]) is dict:
        for key,value in clasList[i].items():
            print(key,value)
    else:
        print (clasList[i])
    print("")


no=0
for row in f:  # uses the 25% leftover from file to test    
    if len(row) <= 1: continue
    no+=1 #counts up remaining records
    
    part=row.strip("\n").split(", ") 
    accur+=checkRec(clasList,part) 


#Print out various results
print("\nGuessed Correctly:",accur,"of",no)
print("Records trained:",under+over)
print("Records tested:",no)
print("total recs:",totalRecs)

accur=round(((accur/no)*100))
print("accuracy:",accur,"%")

f.close()

