#WARNING: this program takes about 7hrs to complete
        #(tested on 2GHz-Dual Core)

def isPrime(num):
    for i in range(2,int(num/2)+1):
        if not num%i:
            return False
    return True

maxi=2000000
tally=0

for i in reversed(range(2,maxi)):
    if(isPrime(i)):
        tally+=i
        print(i)

print("\nTally:",tally)
