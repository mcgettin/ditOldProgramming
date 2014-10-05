def sumSqu(max):
    tally=0
    for i in range(max):
        tally+=((i+1)**2)
    return tally

def sqSum(max):
    tally=0
    for i in range(max):
        tally+=(i+1)
    return (tally**2)    

print("Difference is:",sqSum(100)-sumSqu(100))
