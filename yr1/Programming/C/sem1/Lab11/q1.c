#include <stdio.h>
#define PIE 3.14

int main(){

	float radius,area,diam;
	float *ptr;


	ptr=&radius;

	printf("Enter value for radius: ");
	scanf("%f",ptr);
	diam=radius*2;
	area=PIE*(radius*radius);

	printf("Radius: %.2f\nDiameter: %.2f\nArea: %.2f\n",radius,diam,area);

	return 0;
}

