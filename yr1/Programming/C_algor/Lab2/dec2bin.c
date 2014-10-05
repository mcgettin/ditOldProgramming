#include <stdio.h>
#define SIZE 30

void int2bin(int, int[]);

int main(){
	
	int num;
	int bin[SIZE];
	
	printf("Please insert an unsigned int: ");
	scanf("%d", &num);
	
	int2bin(num,bin);
	
	return 0;
}

void int2bin(int N, int bits[]){
	
	int i=0, number=N;
	
	while(number>0 && i<SIZE){
		bits[i]=number%2;
		number=number/2;
		i++;
	}
	printf("\nNumber: %d\nBinary: ",N);
	for(i=i-1; i>=0; i--){
		printf("%d",bits[i]);
	}
	return;
}
