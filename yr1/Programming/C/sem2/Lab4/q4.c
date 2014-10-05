#include <stdio.h>
#define SIZE 10

void hiElm(int[]);

int main(){

	int arr[SIZE],hi,i;

	printf("Please input 10 integers for arr[]:\n");
	for(i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
	
	hiElm(arr);
	printf("\nElements of arr[] are now:");
	for(i=0;i<SIZE;i++){
		printf("\n%d",arr[i]);
	}
	
	getchar();
	getchar();
	return 0;
}

void hiElm(int nums[]){

	int i;

	for(i=0;i<SIZE;i++){
		nums[i]=nums[i]*2;
	}
}
