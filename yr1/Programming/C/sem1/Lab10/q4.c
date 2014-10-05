#include <stdio.h>
#include <stdlib.h>

int main(){

	int num1,num2,sum,*np1,*np2,*sp;
	
	printf("Please input 2 integers:\n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	getchar();	

	np1=&num1;
	np2=&num2;
	sp=&sum;
	
	*sp=(*np1)*(*np2);
	
	printf("Sum: %d\n",sum);
	
	return 0;
}

