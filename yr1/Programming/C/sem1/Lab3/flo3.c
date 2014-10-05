#include <stdio.h>

//Program to get floats from user and print them out

main(){
	
	float f1,f2,f3;
	
	printf("Please insert three float numbers:\n");
	scanf("%f %f %f",&f1,&f2,&f3);
	printf("Your numbers are:\n%.4f\n%.3f\n%.0f\n",f1,f2,f3);
	
}
