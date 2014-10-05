#include <stdio.h>
#include <stdlib.h>

main(){

	float *ptr;
	int no_els, i;
	
	printf("Enter number of elements you want\n");
	scanf("%d",&no_els);
	
	ptr=(float *)calloc(no_els,sizeof(float));
	if(ptr==NULL){
		printf("\nError: Cannot allocate memory\n");
	}else{
		for(i=0;i<no_els; i++){
			printf("%.1f\n",*(ptr+i));
		}
	}
	free (ptr);
}
