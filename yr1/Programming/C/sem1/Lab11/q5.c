#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(){

	float *arr1,*arr2,hi,low,tally;
	int i;

	arr1=(float*)malloc(SIZE*sizeof(float));
	arr2=(float*)malloc(SIZE*sizeof(float));


	printf("Please enter %d elements for arr1:\n",SIZE);
	for(i=0;i<SIZE;i++){
		scanf("%f",arr1+i);
		getchar();
	}
	printf("[Press Enter]");
	getchar();

	hi=*arr1;
	low=*arr1;
	for(i=0;i<SIZE;i++){
		if(hi<*(arr1+i)){
			hi=*(arr1+i);
		}
		if(low>*(arr1+i)){
			low=*(arr1+i);
		}
	}
	printf("Highest: %f\nLowest: %f\n[Press Enter]",hi,low);
	getchar();

	tally=0;
	for(i=0;i<SIZE;i++){
		tally+=*(arr1+i);
	}
	printf("Average: %f\n[Press Enter]",tally/SIZE);
	getchar();

	for(i=0;i<SIZE;i++){
		*(arr2+i)=*(arr1+SIZE-i-1);
	}
	printf("Arr1: \tArr2: \n");
	for(i=0;i<SIZE;i++){
		printf("%f\t\t%f\n",*(arr1+i),*(arr2+i));
	}
	printf("[Press Enter]");
	getchar();

	free(arr1);
	free(arr2);

	return 0;
}

