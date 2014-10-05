#include <stdio.h>

main(){
	
	float f1,f2;
	
	printf("Please input two floating point numbers:\n");
	scanf("%f %f",&f1,&f2);
	
	printf("Sum is %.3f\nAverage is %.3f\n",(f1+f2),((f1+f2)/2));
	
}
