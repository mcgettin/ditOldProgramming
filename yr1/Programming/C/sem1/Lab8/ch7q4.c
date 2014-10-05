#include <stdio.h>
#define SIZE 15

int main(){

	int arr[SIZE];
	int i;
	
	//read in 15 nums
	printf("Input 15 integers:\n");
	for(i=0; i<SIZE; i++){
		scanf("%d",&arr[i]);
		getchar();
	}
	//(a)
	printf("You Entered:\n");
	for(i=0;i<SIZE;i++){
		printf("%d\n",arr[i]);
	}
	printf("\n");
	//(b)
	printf("You Entered:\n");
	for(i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	//(a)
	printf("You Entered:\n");
	for(i=SIZE;i>0;i--){
		printf("%d ",arr[i-1]);
	}
	printf("\n");
	
	return 0;
}
