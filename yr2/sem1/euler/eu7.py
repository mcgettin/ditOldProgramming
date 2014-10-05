def isPrime(num):
    for i in range(2,int(num/2)+1):
        if not num%i:
            return False
    return True


maxi=10001
pri=1
i=0
while i < 10001:
    pri+=1
    while not isPrime(pri): pri+=1
    i+=1

print("prime #",maxi," is:",pri)  
