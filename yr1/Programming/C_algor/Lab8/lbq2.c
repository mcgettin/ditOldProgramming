// Program for Stack implementation using an Array
#include <stdio.h>
#include <limits.h>         // need this for INT_MAX


#define MAXSIZE 10

int stack[MAXSIZE];         // Stack as an array 
int top = 0;	             // Index pointing to the top of stack
int pop();                  // pop function
void push(int);				 // push function

int main()
{
	int item,i;
	
	printf("Pushing:\n");
	for(i=0;i<MAXSIZE;i++){
		push(i+1);
		printf("%d\n",i+1);
	}
	
	printf("\nPopping:\n");
	while(top!=0){
		printf("%d\n",pop());
	}
	
	printf("\n[Hit ENTER to close]");
	getchar();
	return 0;
}                // end of main program


void push(int item)       // Push item onto the stack.
{
	if(top >= MAXSIZE)    // If stack is full
	{
		printf(" Error ... STACK FULL \n ");
		return;
	}
	else
	{
		stack[top]=item;
		top++;
		// insert the two lines here.
      // copy item into the stack at location top.
      // increment top by one.

   	
	}
}

int pop()                 // pop element from the stack
{
	int item;
	if(top <= 0)          // If stack is empty
	{
		printf(" Error ... STACK EMPTY \n ");
		return INT_MAX;   // return a big integer 
	}
	else
	{
		top--;
		item = stack[top];
	}
	return(item);         // return the item on top.
}
