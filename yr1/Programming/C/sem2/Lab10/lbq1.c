#include <stdio.h>

int main(){

	float euro[5], dollar[5];
	int i;
	const float rate=1.35;
	
	printf("Input 5 values for euro:\n");
	for(i=0;i<5;i++){
		scanf("%f",&euro[i]);
	}
	
	for(i=0;i<5;i++){
		dollar[i]=euro[i];
	}
	
	for(i=0;i<5;i++){
		dollar[i]=euro[i]*rate;
	}
	
	for(i=0;i<5;i++){
		printf("\nDollars: %.2f	Euros: %.2f\n",dollar[i],euro[i]);
	}
	
	printf("\n[Press ENTER to close] ");
	getchar();
	getchar();
	
	return 0;
}
