#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(){

	int i, arr1[MAX],arr2[MAX];
	
	//read in arr1 els 
	printf("Please insert elements for arr1:\n");
	for(i=0;i<MAX;i++){
		scanf("%d",&arr1[i]);
		getchar();
	}
	
	//read in arr2 els 
	printf("Please insert elements for arr2:\n");
	for(i=0;i<MAX;i++){
		scanf("%d",&arr2[i]);
		getchar();
	}
	
	
	//display arr1*arr2
	printf("Product of arr1 and arr2 elements:\n");
	for(i=0;i<MAX;i++){
		printf("element %d: %d\n",i+1,arr1[i]*arr2[i]);
	}

	return 0;
}

