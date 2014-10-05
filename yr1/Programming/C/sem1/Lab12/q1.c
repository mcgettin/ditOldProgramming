#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define TODOLLAR 1.3

int main(){

	//(a) 
	float euro[SIZE],dollar[SIZE];
	int i;
	
	//(b)
	printf("Please enter %d values for euro[]:\n",SIZE);
	for(i=0; i<SIZE; i++){
		scanf("%f",&euro[i]);
		getchar();
	}
	
	//(c) 
	for(i=0;i<SIZE;i++){
		dollar[i]=euro[i];
	}
	
	//(d)
	// 1.3 dollars to 1 euro
	for(i=0;i<SIZE; i++){
		dollar[i]=euro[i]*TODOLLAR;
	}
	
	//(e)
	printf("\nEuro - Dollar\n----------------------------\n");
	for(i=0;i<SIZE;i++){
		printf("(%d) Euro: %.2f\t\t Dollar: %.2f\n",i+1,euro[i],dollar[i]);
	}
	
	return 0;
}
