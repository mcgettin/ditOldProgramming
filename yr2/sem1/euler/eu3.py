#euler3: prime factors of 600,851,475,143

def isPrime(num):
    for i in range(2,int(num/2)+1):
        if not num%i:
            return False
    return True

def getNextFactor(fac,num):
    for i in range(int(fac)+1,int(num/2)+1):
        if (not num%i):
            return i
    return int(num/2)+1



num=600851475143
fac=1
while(fac<(num/2)):
    fac=getNextFactor(fac,num)
    print(".",fac,".")
    if (isPrime(fac)): print("Prime factor of ",num,": ",fac,)

