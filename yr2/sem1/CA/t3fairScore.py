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

def isInt(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False

#tally up raw data into up/down-dict depending on $income (ie. training)
def doRecs(tList,rec):
    for i in range(0,13):
        if i==2 or i==3: continue

        if isInt(rec[i]):
            tList[i] += (int)(rec[i])
        else:
            if rec[i] in tList[i]:
                tList[i][rec[i]] += 1
            else:
                tList[i][rec[i]] = 1
    return 1
        
        
        
        
#taking raw records data and averaging into the classifier dictionary           
def avrRecs(dL,uL,dN,uN):
    avrL=dL
    
    for i in range(0,13):
        if i==2 or i==3: continue
        #print("i:",i)

        if type(avrL[i]) is not dict:
            avrL[i] = ((int)((((uL[i]/uN)+(dL[i]/dN))/2)*1000)/1000)
        else:
            for dKey,dVal in dL[i].items():
                for uKey,uVal in uL[i].items():
                    if dKey==uKey:
                        avrL[i][dKey]= ((int)((((dVal/dN)*len(dL[i])+\
                                                (uVal/uN)*len(uL[i]))/2)*1000)/1000)
    return avrL

#get score for individual records in training (1st 75%)
def recScore(avrL,rec):
    tally=0
    
    for i in range(0,13):
        if i==2 or i==3: continue
        
        if type(avrL[i]) is not dict:
            if (int)(rec[i]) > avrL[i]:
                tally+=1
        else:
            for key,val in avrL[i].items():
                if key == rec[i]:
                    tally+=val

    return tally


#checking new records against classifier,to tally up outcome (ie. testing)
def checkRec(avrL,rec,avrAll):

    tally=recScore(avrL,rec)
    
    if rec[14] == "<=50K":
        return (tally <= avrAll)
    else:
        return not (tally <= avrAll)
        



#read from url       
'''
URL="http://archive.ics.uci.edu/ml/\
machine-learning-databases/adult/adult.data"
print("Url requesting...")
local,headers=urllib.request.urlretrieve(URL)
f=open(local,'r')        
'''

f=open("whole.txt","r")

downL=[0,{},0,{},0,{},{},{},{},{},0,0,0]
upL=[0,{},0,{},0,{},{},{},{},{},0,0,0]

totalRecs=tallyRecs(f)
accur,up,down,i,avrD,avrU,avrAll=0,0,0,0,0,0,0

for row in f:
    i+=1
    if i >= totalRecs*0.75: break # use 75% of file for training
    
    if len(row) <= 1: continue
    part=row.strip("\n").split(", ")
    
    if part[14] == "<=50K":
        down+=doRecs(downL,part)
    else:   
        up+=doRecs(upL,part)

print("\ndownL:\n----------")
for i in  range(0,13):
    if i==2 or i==3: continue
    if type(downL[i]) is dict:
        print("length",len(downL[i]))
        for key,value in downL[i].items():
            print(key,value/down)
    else:
        print (downL[i]/down)
    print("")

print("\nupL:\n----------")
for i in  range(0,13):
    if i==2 or i==3: continue
    if type(upL[i]) is dict:
        print("length",len(upL[i]))
        for key,value in upL[i].items():
            print(key,value/up)
    else:
        print (upL[i]/up)
    print("")
        

clasL=avrRecs(downL,upL,down,up) #creating classifier

print("\navrL:\n----------")
for i in  range(0,13):
    if i==2 or i==3: continue
    if type(clasL[i]) is dict:
        for key,value in clasL[i].items():
            print(key,value)
    else:
        print (clasL[i])
    print("")


f.seek(0,0)
i=0
for row in f:
    i+=1
    if i >= totalRecs*0.75: break # use 75% of file for training
    
    if len(row) <= 1: continue
    part=row.strip("\n").split(", ")
    
    if part[14] == "<=50K":
        avrD+=recScore(clasL,part)
    else:   
        avrU+=recScore(clasL,part)


print("avrD",avrD)
print("avrU",avrU)
print("avrAll:",avrAll)

avrD/=down
avrU/=up
avrAll=((int)(((avrD+avrU)/2)*1000)/1000)

print("avrD",avrD)
print("avrU",avrU)
print("avrAll:",avrAll)

        
for row in f:  # uses the 25% leftover from file to test    
    if len(row) <= 1: continue
    part=row.strip("\n").split(", ")
    
    accur+=checkRec(clasL,part,avrAll) 


print("\nGuessed Correctly:",accur,"of",(int)(totalRecs*0.25))
print("Records trained:",up+down)
print("Records tested:",(int)(totalRecs*0.25))
print("total recs:",totalRecs)

accur=round(((accur/(totalRecs*0.25))*100))
print("accuracy:",accur,"%")

f.close()

