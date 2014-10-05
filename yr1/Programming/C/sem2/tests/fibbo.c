#include <stdio.h>

int main(){
	unsigned int prev=0, fib=1, max;
	
	printf("Calculate fibonacci sequence up to:\nN = ");
	scanf("%d",&max);
	getchar();
	
	printf("\nSequence is:\n%d",prev);
	while(fib<max){
		printf(", %d",fib);
		fib+=prev;	
		prev=fib-prev;
	}
	
	
	printf("\n\n\n[Press ENTER to close]");
	getchar();
	return 0;
}
