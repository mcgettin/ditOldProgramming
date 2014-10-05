#include <stdio.h>

int main(){
	
	float in1=5.223,in2=100.7;
	float *ptr1,*ptr2;
	
	ptr1=&in1;
	ptr2=&in2;
	
	printf("Addresses of variables:\n");
	printf("in1: %p\nin2: %p\nptr1: %p\nptr2: %p\n",&in1,&in2,&ptr1,&ptr2);
	printf("Contents of:\nptr1: %p\nptr2: %p\n", ptr1,ptr2);
	printf("Contents of address at:\nptr1: %f\nptr2: %f\n",*ptr1,*ptr2);
	
	return 0;
}

