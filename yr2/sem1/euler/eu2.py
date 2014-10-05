pre,fib,tally=0,1,0
MAX=4000000

while fib <= MAX:
    if(not fib%2): tally+=fib
        
    pre,fib=fib,pre+fib
   

print("\ntally is: ",tally)
input("\n[press ENTER to end program]")
