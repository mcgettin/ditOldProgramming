#Roman numeral converter
print("Program: Roman Numeral Converter")
print("--------------------------------------------------------\n"\
      "M.= 1,000,000   D.= 500,000   C.= 100,000   L.= 50,000\n"\
      "X.= 10,000      V.= 5,000\n\n"\
      "M = 1,000       D = 500       C = 100       L = 50\n"\
      "X = 10          V = 5         I = 1\n"\
      "--------------------------------------------------------")

def safeIntGrab(MIN,MAX):
    i=0.0
    while type(i) is not int:
        print("\nPlease input an integer (",MIN,"-",MAX,"): ")
        i=input("Integer: ")
        try:
            i=int(i)
            if i not in range(MIN,MAX+1):
                print("[input must be in range]")
                i=0.0
        except ValueError:
            print("[input must be an int]")
    
    return i

romeLet=["M̅","D̅","C̅","L̅","X̅","V̅","M","D","C","L","X","V","I"]
romeVal=[1000000,500000,100000,50000,10000,5000,1000,500,100,50,10,5,1]
conv=""

num=safeIntGrab(1,3999999)


while num > 0:
    for i in range(13):    
        if num/romeVal[i] >= 1:
            while(num>=romeVal[i]):
                conv+=romeLet[i]
                num-=romeVal[i]

#print("Roman (raw): ",conv)

for i in range(2,13):
    if romeLet[i]*4 in conv:
        if romeLet[i-1] in conv:
            conv=conv.replace(romeLet[i-1]+romeLet[i]*4, romeLet[i]+romeLet[i-2])
        else:
            conv=conv.replace(romeLet[i]*4,romeLet[i]+romeLet[i-1])
   
print("\nRoman: ",conv)

input("\n\nPlease hit [ENTER] to close...")
exit()