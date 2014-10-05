#include <stdio.h>
#define SIZE 4

main(){
	
	int arr[SIZE];
	int temp,i;
	
	printf("Please insert 4 integers:\n");
	for(i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
	for(i=0; i<SIZE; i++){
		printf("arr[%d]: %d\n",i,arr[i]);
	}
	
	temp=arr[0];
	arr[0]=arr[1];
	arr[1]=temp;
	printf("\n");
	temp=arr[2];
	arr[2]=arr[3];
	arr[3]=temp;
	
	for(i=0; i<SIZE; i++){
		printf("arr[%d]: %d\n",i,arr[i]);
	}
}
