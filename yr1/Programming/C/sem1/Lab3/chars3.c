#include <stdio.h>

//Program to get 2 characters from user and display them

main(){
	
	char c1,c2;
	
	printf("Please insert two characters:\n");

	scanf("%c %c", &c1,&c2); //getting 2 chars

	printf("\nYour characters were: %c and %c.\n", c1,c2);

}
