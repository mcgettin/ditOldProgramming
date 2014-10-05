#program to calculate all perfect numbers up to a user defined maximum
print("--==Perfect number finder program==--")
max=int(input("Enter max number: "))
cur=1
print("\nPerfect numbers include:")
while(cur<max+1):
    sum=0
    pro=cur-1         #product, starts at current num being checked -1
    while(pro>0):
        if(cur%pro==0):  #if valid product of current num being checked:
            sum+=pro    #add to valid product sum
        pro-=1          #check for next product
    
    if(sum==cur):       #if sum of products is same as number:
        print(cur)      #it's a perfect number
    cur+=1              #check for next perfect number

print("\nDone")
input("[Press ENTER to close]")
