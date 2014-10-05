#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int main(){

	int i;
	float *arr1,*arr2;
	
	arr1=(float*)malloc(SIZE*sizeof(float));
	arr2=(float*)malloc(SIZE*sizeof(float));
	
	printf("Please input %d floats for 'arr1':\n",SIZE);
	for(i=0; i<SIZE;i++){
		scanf("%f",arr1+i);
	}
	getchar();
	
	for(i=0; i<SIZE;i++){
		*(arr2+i)=*(arr1+i);
	}
	
	printf("Arr1:\n");
	for(i=0; i<SIZE;i++){
		printf("pos %d: %.3f\n",i+1,arr1[i]);
	}
		
	printf("Arr2:\n");
	for(i=0; i<SIZE;i++){
		printf("pos %d: %.3f\n",i+1,arr2[i]);
	}
	
	free(arr1);
	free(arr2);
	return 0;
}

