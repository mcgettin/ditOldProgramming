#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int main(){

	int *arr1,*arr2,i;

	arr1=(int*)malloc(SIZE*sizeof(int));
	arr2=(int*)malloc(SIZE*sizeof(int));

	printf("Please insert 3 integers for arr1:\n");
	for(i=0;i<SIZE;i++){
		scanf("%d",arr1+i);
	}

	printf("Copying contents of arr1 to arr2...\n[Press Enter]\n");
	getchar();

	for(i=0;i<SIZE;i++){
		*(arr2+i)=*(arr1+i);
	}

	printf("arr2:\n");
	for(i=0;i<SIZE;i++){
		printf("%d\n",*(arr2+i));
	}

	free(arr1);
	free(arr2);

	return 0;
}
