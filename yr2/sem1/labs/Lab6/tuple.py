#fractions program

#this function finds the Greatest Common Denominator of two integers
def gcd(num,denum):
    while denum != 0:
        temp=denum
        denum=num%temp
        num=temp
    return num

#this function finds the Lowest Common Multiple of two integers
def lcm(num,denum):
    nTemp=num
    dTemp=denum
    while nTemp != dTemp:
        if(nTemp > dTemp):
            dTemp+=denum
        else:
            nTemp+=num
    return nTemp

#function to add two fraction tuples together. Returns added fraction
def addFrac(f1,f2):
    denum=int(lcm(f1[1],f2[1]))
    num=int((f1[0]*(denum/f1[1]))+(f2[0]*(denum/f2[1])))
    frac=(num,denum)
    return frac

#function to subtract two fraction tuples together. Returns subbed fraction
def subFrac(f1,f2):
    denum=int(lcm(f1[1],f2[1]))
    num=int((f1[0]*(denum/f1[1]))-(f2[0]*(denum/f2[1])))
    frac=(num,denum)
    return frac

#function that reduces a fraction down to its simplest form
def reduce(frac):
    great=gcd(frac[0],frac[1])
    frac=(int(frac[0]/great),int(frac[1]/great))
    return frac

opt=-1

while(opt!=0):
    print("\n\nMenu:\n1. Add two fractions\n2. Subtract two fractions\n\
3. Simplify a fraction\n4. Find GCD\n5. Find LCM\n0. Exit\n")
    opt=int(input("Choice (0-5): "))

    if(opt==0): break

    elif(opt==1 or opt==2):
        #Inputs 1st fraction
        print("\nFraction 1: (a,b)")            
        n1=int(input("  numerator: "))
        d1=int(input("denumerator: "))

        #Inputs 2nd fraction    
        print("\nFraction 2: (x,y)")            
        n2=int(input("  numerator: "))
        d2=int(input("denumerator: "))

        #convert to tuples
        frac1=(n1,d1)
        frac2=(n2,d2)
        
        if(opt==1):
            print("\nAdded is: ", addFrac(frac1,frac2))
            input("\n[Press ENTER to contiue]\n")
        else:
            print("\nSubtracted is: ", subFrac(frac1,frac2))
            input("\n[Press ENTER to contiue]\n")
        
    elif(opt==3):
        #Inputs fraction
        print("\nFraction 1: (a,b)")            
        n1=int(input("  numerator: "))
        d1=int(input("denumerator: "))

        #to tuple
        frac1=(n1,d1)
        
        print("\nSimplified is: ", reduce(frac1))
        input("\n[Press ENTER to contiue]\n")
        
    elif(opt==4):
        small=int(input("Smaller: "))
        big=int(input("Bigger: "))
        
        print("\nGCD is: ", gcd(big,small))
        input("\n[Press ENTER to contiue]\n")
        
    elif(opt==5):
        num1=int(input("1st number: "))
        num2=int(input("2nd number: "))
        
        print("\nGCD is: ", lcm(num1,num2))
        input("\n[Press ENTER to contiue]\n")

    else:
        print("\nError: Invalid selection")
        input("\n[Press ENTER to contiue]\n")
        
input("\n[Press ENTER to close]")
print("\n\n\n")
