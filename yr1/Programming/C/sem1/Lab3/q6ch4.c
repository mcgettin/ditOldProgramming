#include <stdio.h>

//q6,chapter4

main(){
	
	float fah;
	float cels;
	
	printf("Please insert temperature in degrees fahrenheit:\n");
	scanf("%f",&fah);
	
	cels=(fah-32.0)*(5.0/9.0);
	
	printf("In celsius that's: %.1f'C\n", cels);
	
}
