#include <stdio.h>
#define SIZE 3

float avrArr(int[]);

int main(){

	int nums[SIZE],i;
	float avr;
	
	printf("Please insert %d numbers:\n",SIZE);
	for(i=0;i<SIZE;i++){
		scanf("%d",&nums[i]);
	}
	
	avr=avrArr(nums);
	
	printf("\nThe average of nums[] is: %.2f\n",avr);
	
	printf("\n[Press any key to close]");
	getchar();
	getchar();
	return 0;
	
}

float avrArr(int arr[]){
	
	int i;
	float mean=0.0;
	
	for(i=0; i<SIZE; i++){
		mean+=arr[i];
	}
	mean=(mean/SIZE);
	
	return mean;
}
