#include <stdio.h>
#define SIZE 10

float avrElms(int[]);

int main(){

	int arr[SIZE],i;
	float avr;

	printf("Please input 10 integers for arr[]:\n");
	for(i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
	
	avr=avrElms(arr);
	printf("\nAverage of arr[] is: %.3f\n",avr);
	
	getchar();
	getchar();
	return 0;
}

float avrElms(int nums[]){

	int i,total=0;
	float mean;

	for(i=0;i<SIZE;i++){
		total+=nums[i];
	}
	mean=(
	(float)total/SIZE);
	return mean;
}
