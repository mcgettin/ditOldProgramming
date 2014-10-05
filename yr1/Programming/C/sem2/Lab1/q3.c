#include <stdio.h>
#include <stdlib.h>

int main(){

	int *ptr; 
	float *pav;
	int no_els, no_bytes, i;
	
	printf("Enter number of elements you want in block: ");
	scanf("%d",&no_els);
	
	no_bytes=no_els*sizeof(int);
	ptr=(int *)malloc(no_bytes);
	pav=(float *)calloc(1,sizeof(float));
	
	if(ptr==NULL){
		free(ptr);
		free(pav);
		printf("\nError: Cannot allocate memory\n");
		return 1;
	}
	printf("\nPlease enter values for your elements:\n");
	for(i=0;i<no_els; i++){
		scanf("%d",ptr+i);
	}
	for(i=0;i<no_els; i++){
		*pav+=*(ptr+i);
	}
	*pav=(float)((*pav)/no_els);
	
	printf("average: %.2f\n",*pav);
	
	free(ptr);
	free(pav);
	return 0;
}
