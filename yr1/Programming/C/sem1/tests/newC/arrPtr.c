//Program tp access an array using pointers rather than sub-sript
#include <stdio.h>
#define SIZE 5

int main(){

	int i, arr[SIZE];

	printf("Please insert %d integers:\n",SIZE);
	for(i=0; i<SIZE; i++){
		scanf("%d",arr+i);
	}

	printf("arr[] elements are:\n");
	for(i=0; i<SIZE; i++){
		printf("Element %d: %d\n",i+1, *(arr+i));
	}
	
	printf("\n[press any key to close]");
	getchar();
	getchar();
	return 0;
}

