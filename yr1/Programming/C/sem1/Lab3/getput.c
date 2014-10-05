#include <stdio.h>

//Program to get 2 chars from user, using getchar() and putchar()

main(){
	
	char c1,c2;
	
	printf("Please insert two charaters:\n");
	c1=getchar();
	getchar();
	c2=getchar();
	printf("You entered:\n");
	putchar(c1);
	printf("\n");
	putchar(c2);
	
}
