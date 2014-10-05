#include <stdio.h>

//q4,chapter4

main(){
	
	float v1,v2,v3;
	
	printf("Please input three temperature values in celcius:\n");
	scanf("%f %f %f",&v1,&v2,&v3);
	
	v1=(v1/(5.0/9.0))+32.0;
	v2=(v2/(5.0/9.0))+32.0;
	v3=(v3/(5.0/9.0))+32.0;
	
	printf("Your values in fahrenheit are:\n%.2f\n%.2f\n%.2f\n",v1,v2,v3);
	
}
