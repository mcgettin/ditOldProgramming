#include <stdio.h>
#define SIZE 5

main(){
	
	int i, nums[SIZE];
	printf("Please insert 5 integers:\n");
	for(i=0; i<SIZE; i++){
		scanf("%d",&nums[i]);
	}
	int arr[SIZE];
	for(i=0; i<SIZE; i++){
		arr[i]=nums[i];
	}
	for(i=0; i<SIZE; i++){
		printf("arr[%d]: %d\n",i,arr[i]);
	}
}
