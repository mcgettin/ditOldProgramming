x = int(input("Enter number "))
guess = 1.0
#while ((guess*guess - x) > 0.00001) or ((x - guess*guess) > 0.00001):
while abs(guess**2 - x) > 0.00001:
	guess = (guess + x/guess)/2
	print ("Intermediate result: ",guess)
	
print ("-"*10,"\nFinal Result: ",guess,"\n","-"*10, sep='')

# Do the same thing, but in a function
def sqrt_guess(x):
	guess = 1.0
	while abs(guess**2 - x) > 0.00001:
		guess = (guess + x/guess)/2
	return guess

# Invoke the function and print the result	
print("\n{:5.3f} returned by function".format(sqrt_guess(x)))
