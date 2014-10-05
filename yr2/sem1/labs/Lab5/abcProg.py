myfile=open("hnr1.abc","r")

for line in myfile:
 
    if len(line)==0:
        break
    
    if(line[0:2]=="X:"):
        t=0
        print("ID:",line[2:-1],end="  ...  ")
    elif(line[0:2]=="T:"):
        if t==0:
            t=1
            print("Title:",line[2:-1],end="  ...  ")
            
    elif(line[0:2]=="M:"):
        t=0
        print("Time:",line[2:4],end="  ...  ")
    elif(line[0:2]=="K:"):
        t=0
        print("Key:",line[2:-1],end=" ... ")   
        print("\n")
        
myfile.close()
