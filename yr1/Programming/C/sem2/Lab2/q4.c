#include <stdio.h>

void sum(int,int,int);
void average(int);

int main(){

	int num1,num2,num3;

	printf("Please input integers: \n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	scanf("%d",&num3);
	
	sum(num1,num2,num3);
	
	return 0;
}

void sum(int n1,int n2,int n3){

	int nSum;
	nSum=n1+n2+n3;
	average(nSum);
	
}

void average(int n){
	
	printf("The average of the 3 numbers is: %.3f\n", (float)(n/3));
	
}
