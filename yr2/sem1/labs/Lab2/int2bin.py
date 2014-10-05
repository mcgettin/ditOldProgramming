#You prompt for an integer, convert the integer to a binary number
#string (there is no type for actual binary numbers so we just
#represent it as a string). We then take the string and turn it
#back into a regular integer. Things to remember

#If the integer is 0, then we are done since conversion
#back and forth of 0 is still 0. The program simply
#prints a note saying it is 0 and quits.

#If the integer is negative, then we probably don’t know
#how to do it, so the program prints a message saying
#it is negative and quits.

#Otherwise, we do the conversion of the integer to a
#binary string (a string of 1’s and 0’s) and then convert
#that same string back to an integer to make sure we did it right.

choose=int(input("would you like to convert:\n1.INT to BIN\n2.BIN to INT\
\n3.Exit program\n"))

if(choose==1):
    conv=""

    num = int(input("Please insert INT to convert: "))

    if num is 0:
        print ("Answer is: ", num)

    elif num < 0:
        print ("Error: negative number!")

    else:
        while num > 0:
            conv=str(int(num%2)) + conv
            
            num=int(num/2)
        
        print ("Answer is: ", conv)

elif(choose==2):
        
    conv=input("Please input a binary number to convert: ")

    pow=0
    sum=0

    for c in reversed(conv):
        sum+=(2**pow)*int(c)
        pow+=1

    print("Answer is: ",sum)

elif(choose!=3):
    print("Error!")

else:
    print("goodbye")
    

input("\nPress enter to close");


