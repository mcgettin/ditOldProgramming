#include <stdio.h>

//Chapter 4, Q2

main(){
	
	char c;
	int i;
	float f;
	long l;
	double d;
	
	printf("Input a char, an int, a float, a long and a double:\n");
	scanf("%c %d %f %lu %lf", &c, &i, &f, &l, &d);
	printf("You entered:\n%c \n%d \n%f \n%lu \n%lf",c,i,f,l,d);
	
}
