# from an Integer to base-X (2-16)
def int2X(num,base): 

    ans="" #answer will be i string format
    
    if num is 0:
        print ("Answer is: ", num)

    elif num < 0:
        print ("Error: negative number!")

    else:
        while num > 0:
            ans=digits[num%base]+ans  #the maths...
            num=int(num/base)  #the maths...
            
    return ans

# from base-X (2-16) to Integer
def X2int(num,base):

    num=num.upper() #standardize string input
    
    pow=0
    ans=0

    for c in reversed(num):  #loop backwards through num
        j=0  #used in for loop
        for i in digits:  #loop through digits (i is not needed)
            if(digits[j]==c):
                c=str(j);
            j+=1
        ans+=(base**pow)*int(c) #the maths...
        pow+=1 #move up through powers as move through input

    return ans 

#make digits global so both functions can use them from here
global digits
digits="0123456789ABCDEF"

#give user a menu
choose=int(input("Would you like to:\n1. Convert from INT to another base\
             \n2. Convert to any base number to INT\n0. Exit\n--> "))

#user wants to convert an integer to another base (2-16)
if(choose==1):
    num = int(input("Please insert INT to convert: "))
    base= int(input("input base to convert to (2-16): "))

    print("answer is: ",int2X(num,base)) #calls function and outputs answer


#user wants to convert a number of base 2-16 to an integer
elif(choose==2):
    base = int(input("input base to convert from (2-16): "))
    num = str(input("Please insert number to convert to INT: "))
    
    print("Answer is: ",X2int(num,base))

#user wants to quit early
elif(choose==0):
    print("Goodbye")

#user inputs incorrectly
else:
    print("Error: invalid input")


input("\n[Press ENTER to close]");

