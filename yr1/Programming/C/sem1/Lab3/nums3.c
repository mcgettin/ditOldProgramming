#include <stdio.h>

//Program to get 3 numbers from user and display them

main(){
	
	int num1,num2,num3;
	
	printf("Please insert three integers:\n");

	scanf("%d %d %d", &num1,&num2,&num3); //getting 3 nums

	printf("\nYour numbers were: %d, %d and %d.\n", num1,num2,num3);

}
