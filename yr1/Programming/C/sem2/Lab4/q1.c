#include <stdio.h>
#define PI 3.14159

void area_sq(int*);
void area_circ(float*);

int main(){

	int length;
	float radius;
	
	printf("Enter side length of square: ");
	scanf("%d",&length);
	printf("Enter radius of circle: ");
	scanf("%f",&radius);
	
	area_sq(&length);
	area_circ(&radius);
	
	printf("Area of square: %d\n",length);
	printf("Area of circle: %.3f\n",radius);
	
	getchar();
	getchar();
	return 0;
}

void area_sq(int * len){
	*len=(*len)*(*len);
}

void area_circ(float * rad){
	*rad=PI*(*rad)*(*rad);
}
