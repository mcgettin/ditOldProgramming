#include <stdio.h>
#include <stdlib.h>

main(){

	int *ptr;
	int no_els, no_bytes, i;
	
	printf("Enter number of elements you want in block: ");
	scanf("%d",&no_els);
	
	no_bytes=no_els*sizeof(int);
	ptr=(int*)malloc(no_bytes);
	
	if(ptr==NULL){
		printf("\nError: Cannot allocate memory\n");
	}else{
		printf("\nPlease enter values for your elements:\n");
		for(i=0;i<no_els; i++){
			scanf("%d",ptr+i);
		}
		
		for(i=0;i<no_els; i++){
			printf("\n%d",*(ptr+i));
		}
	}
	free(ptr);
}
