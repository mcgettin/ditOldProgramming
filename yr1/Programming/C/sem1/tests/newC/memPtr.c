#include <stdio.h>
#include <stdlib.h>
#define UNITS 10

int main(){

	int i, *ptr;
	ptr=(int*)malloc(UNITS*sizeof(int));

	if(ptr==NULL){
		free(ptr);
		printf("\nError allocating memory.\n[Press Enter to close]");
		getchar();
		return 1;
	}
	printf("\nPlease enter %d integers:\n",UNITS);
	for(i=0; i<UNITS; i++){
		scanf("%d",ptr+i);
		getchar();
	}
	printf("Contents of allocated memory:\n");
	for(i=0; i<UNITS; i++){
		printf("Position %d: %d\t(address: %p)\n",i+1, *(ptr+i), ptr+i);
	}
	printf("\n");

	free(ptr);
	return 0;
}

