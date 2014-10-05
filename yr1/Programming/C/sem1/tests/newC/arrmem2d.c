//Mem alloc for 2-d arrays
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(){

	int no_rows, no_cols,i,j;
	int **a;

	printf("Please input number of rows: ");
	do{
		scanf("%d",&no_rows);
	}while(no_rows>MAX);
	printf("Please input number of columns: ");
	do{
		scanf("%d",&no_cols);
	}while(no_cols>MAX);

//Alloate memory for each element if a.
	a= (int **)malloc(no_rows * sizeof(int *));

	for(i=0;i<no_rows; i++){
		a[i]=(int *) malloc(no_cols*sizeof(int));
		if(a[i]==NULL){
			printf("Cannot allocate memory\n");
			return 1;
		}
	}

//Enter value for each element of array
	printf("\nPlease enter values for array:\n");
	for(i=0; i<no_rows; i++){
		printf("Row %d\n",i+1);
		for(j=0;j<no_cols; j++){
			printf("\tColumn %d: ",j+1);
			scanf("%d",&a[i][j]);
		}
	}

//Print out all elements in array
	printf("\nArray:\n");
	for(i=0; i<no_rows; i++){
		printf("Row %d\n",i+1);
		for(j=0;j<no_cols; j++){
			printf("\tColumn %d: %d\n",j+1,a[i][j]);
		}
	}
	printf("a is size : %d",sizeof(a));
//Free all inner pointers and pointer to pointers: a
	for(i=0; i<no_rows; i++){
		free(a[i]);
	}
	free(a);
	getchar();
	getchar();
	return 0;
}

