#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main(void){

	int i,j;
	int * nums;
	
	
	for(i=1; i<MAX; i++){
		nums=(int *)realloc(nums,(i+1)*sizeof(int));
		*(nums+((i-1)*sizeof(int)))=i;
		
		printf("\nnums: ");
		for(j=0;j<i;j++){
			printf("\n %d %p ",*(nums+(j*sizeof(int))),nums+(j*sizeof(int)));
		}
		getchar();
	}
	
	free(nums);
	getchar();
	return 0;
}
