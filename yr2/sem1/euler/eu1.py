print("Sum of multiples of 3 or 5 under 1000")
input("[press start to begin]")

i=0
total=0
while i < 1000:
    if(i%5==0 or i%3==0):
        total+=i
        
    i+=1

print("Answer is: ",total)
