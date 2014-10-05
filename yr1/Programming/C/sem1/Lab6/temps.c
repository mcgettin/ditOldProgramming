#include <stdio.h>
#define SIZE 3

main(){
	int i;
	float temps[SIZE];
	printf("Please insert 3 temperatures in Farenheit:\n");
	for(i=0; i<SIZE; i++){
		scanf("%f", &temps[i]);
	}
	for(i=0; i<SIZE; i++){
		printf("Farenheit %d: %f\n",i+1,temps[i]);
		temps[i]=(temps[i]-32.0)*(5.0/9.0);
		printf("Celsius %d: %f\n\n",i+1,temps[i]);
	}
	
	
}
