#include <stdio.h>

main(){
	
	int num1=5;
	char ch1='x';
	int *ptr1;
	char *ptr2;
	
	ptr1=&num1;
	ptr2=&ch1;
	
	printf("The contents of num1 is %d and of ch1 is %c\n",num1,ch1);
	printf("The address of num1 is %p and of ch1 is %p\n\n", &num1,&ch1);
	printf("The contents of ptr1 is %p and of ptr2 is %p\n",ptr1,ptr2);
	printf("The contents of the address pointed to by ptr1 is %d and of ptr2 is %c\n",*ptr1,*ptr2);
	
	
	
}

