#include <stdio.h>
#define SIZE 10

int hiElem(int[]);

int main(){

	int arr[SIZE],hi,i;

	printf("Please input 10 integers for arr[]:\n");
	for(i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
	
	hi=hiElm(arr);
	printf("\nHighest element in arr[] is: %d\n",hi);
	
	getchar();
	getchar();
	return 0;
}

int hiElm(int nums[]){

	int i, big=nums[0];

	for(i=1;i<SIZE;i++){
		if(big<nums[i]){
			big=nums[i];
		}
	}
	return big;
}
