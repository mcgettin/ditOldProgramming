#Program to encrypt/decrypt a string
#most of the work here is self-explanatory

choose=int(input("Would you like to:\n1. Encrypt a string\
                   \n2. Decrypt a string\n0. Exit\n--->"))

if(choose==1):
    text=input("Input string to encrypt: ")
    code=""

    for c in reversed(text): #since string is to be reversed during encrypt
        code+=chr(ord(c)+1) #ord() - char to ASCII, chr() - ASCII to char
    print("Code is: ",code)


elif(choose==2):  #same as above, but -1 instead of +1 to ASCII value
    code=input("Input string to decrypt: ")
    text=""

    for c in reversed(code):
        text+=chr(ord(c)-1)

    print("Text is: ",text)
    

elif(choose==0):
    print("Goodbye")


else:
    print("Error: Invalid Choice")



input("\n[Press ENTER to close]");    
