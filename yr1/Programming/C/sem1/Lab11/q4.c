#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int main(){

	int i;
	float *arr1;

	arr1=(float*)malloc(SIZE*sizeof(float));

	printf("Please insert 3 integers:\n");
	for(i=0;i<SIZE;i++){
		scanf("%f",arr1+i);
	}

	printf("arr1:\n");
	for(i=-1;i<SIZE+1;i++){
		printf("pos %d: %f\n",i,*(arr1+i));
	}

	free(arr1);

	return 0;
}
