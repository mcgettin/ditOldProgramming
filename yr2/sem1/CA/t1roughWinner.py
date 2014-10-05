#modules for ordering a dictionary and url requests
from collections import OrderedDict
import urllib.request

#Record Legend
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

#tally up raw data into up/down-dict depending on $income (ie. training)
def doRecs(tDict,rec):
    for i in range(0,13):
        if i==2 or i==3: continue

        if i==0:
            tDict["Age"]+=(int)(rec[i])
        elif i==4:
            tDict["EdNum"]+=(int)(rec[i])
        elif i==10:
            tDict["CapG"]+=(int)(rec[i])
        elif i==11:
            tDict["CapL"]+=(int)(rec[i])
        elif i==12:
            tDict["Hours"]+=(int)(rec[i])
        else:
            if rec[i] in tDict:
                tDict[rec[i]] += 1
            else:
                tDict[rec[i]] = 1


#taking raw records data and averaging into the classifier dictionary           
def avrRecs(dDict,uDict,down,up):
    avrDict={}
    avrDict["Age"]= (int)((dDict["Age"]/down + uDict["Age"]/up)/2)
    avrDict["EdNum"]= (int)((dDict["EdNum"]/down + uDict["EdNum"]/up)/2)
    avrDict["CapG"]= (int)((dDict["CapG"]/down + uDict["CapG"]/up)/2)
    avrDict["CapL"]= (int)((dDict["CapL"]/down + uDict["CapL"]/up)/2)
    avrDict["Hours"]= (int)((dDict["Hours"]/down + uDict["Hours"]/up)/2)

    for dKey,dVal in dDict.items():
        if dKey=="Age" or dKey=="EdNum" or dKey=="CapG" or dKey=="CapL" or dKey=="Hours": continue
        for uKey,uVal in uDict.items():
            if dKey==uKey:
                #avrDict[dKey]=((int)((((dVal/down)+(uVal/up))/2)*1000)/1000)
                if dVal/down >= uVal/up:
                    avrDict[dKey]=-1
                else:
                    dVal/down < uVal/up
                    avrDict[dKey]=1
            
                
                
    return avrDict

#checking new records against classifier,to tally up outcome (ie. testing)
def checkRec(tDict,rec):
    tally=0

    for i in range(0,13):
        if i==2 or i==3: continue

        if i==0:
            if (int)(rec[i]) > tDict["Age"]:
                tally+=1
            else:
                tally-=1
        if i==4:
            if (int)(rec[i]) > tDict["EdNum"]:
                tally+=1
            else:
                tally-=1
        if i==10:
            if (int)(rec[i]) > tDict["CapG"]:
                tally+=1
            else:
                tally-=1
        if i==11:
            if (int)(rec[i]) > tDict["CapL"]:
                tally+=1
            else:
                tally-=1
        if i==12:
            if (int)(rec[i]) > tDict["Hours"]:
                tally+=1
            else:
                tally-=1        
        else:    
            if rec[i] in tDict:
                tally += tDict[rec[i]]
    #print(tally)
    #input("")

    if rec[14] == "<=50K":
        return (tally <= 0)
    else:
        return not (tally <= 0)
        
#read from url       
'''
URL="http://archive.ics.uci.edu/ml/\
machine-learning-databases/adult/adult.data"
print("Url requesting...")
local,headers=urllib.request.urlretrieve(URL)
f=open(local,'r')        
'''

f=open("whole.txt","r")

downDict={"Age":0,\
          "EdNum":0,\
          "CapG":0,\
          "CapL":0,\
          "Hours":0}
upDict={"Age":0,\
        "EdNum":0,\
        "CapG":0,\
        "CapL":0,\
        "Hours":0}
    
totalRecs=tallyRecs(f)
accur,over,under,i=0,0,0,0

for row in f:
    i+=1
    if i >= totalRecs*0.75: break # use 75% of file for training
    
    if len(row) <= 1: continue
    part=row.strip("\n").split(", ")
    
    if part[14] == "<=50K":
        doRecs(downDict,part)
        under+=1
    else:   
        doRecs(upDict,part)
        over+=1

print("\ndownDict:\n----------")
for key, value in sorted(downDict.items()):
    print (key,((int)((value/under)*1000))/1000)

print("\nupDict:\n----------")
for key, value in sorted(upDict.items()):
    print (key,((int)((value/over)*1000))/1000)

clasDict=avrRecs(downDict,upDict,under,over) #creating classifier

print("\nClassifier:\n----------")
for key, value in sorted(clasDict.items()):
    print (key, value)

for row in f:  # uses the 25% leftover from file to test    
    if len(row) <= 1: continue
    part=row.strip("\n").split(", ")
    
    accur+=checkRec(clasDict,part) 


print("\nGuessed Correctly:",accur,"of",(int)(totalRecs*0.25))
print("Records trained:",under+over)
print("Records tested:",(int)(totalRecs*0.25))
print("total recs:",totalRecs)

accur=round(((accur/(totalRecs*0.25))*100))
print("accuracy:",accur,"%")

f.close()

