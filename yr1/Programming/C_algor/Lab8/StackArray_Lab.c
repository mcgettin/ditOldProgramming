// Program for Stack implementation using an Array

#include <stdio.h>
#include <limits.h>         // need this for INT_MAX
#include <ctype.h>

#define MAXSIZE 10

int stack[MAXSIZE];         // Stack as an array 
int top = 0;	             // Index pointing to the top of stack
int pop();                  // pop function
void push(int);				 // push function

int main()
{
	int option = 1, item;

	while(option != 3)
	{
		printf("\n MAIN MENU: \n" );
		printf(" 1 - Add item to stack \n");
		printf(" 2 - Delete item from stack\n");
		printf(" 3 - Exit the program \n");
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				printf(" Enter the data... ");
				scanf("%d", &item);
				push(item);            // push the item on stack
				break;

			case 2:
				item = pop();          // pop an item from stack
				if (item != INT_MAX)   // its not a big integer
					printf(" Item popped from stack = %d \n",item);
				break;

			case 3:
				printf("Quiting the Program.\n");
				break;

			default:
				printf("Invalid Choice, try again. \n ");
		}
	}// end of outer while loop
	printf("Stack contains (top to bottom):\n");
	while(top!=0){
		printf("%d\n",pop());
	}
	printf("\n\n[Hit ENTER to close]");
	getchar();
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
