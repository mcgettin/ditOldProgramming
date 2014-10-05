#include <stdio.h>
#include <stdio.h>
#define ROW 4
#define COL 5

int main(){

	int i,j,arr[ROW][COL];
	
	//read in values
	printf("Please insert elements into 'arr':\n");
	for(i=0;i<ROW;i++){
		printf("Row %d:\n",i+1);
		for(j=0;j<COL;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	//print values below zero
	printf("Elements under zero:\n");
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(arr[i][j]<0){
				printf("Row %d:\n",i+1);
				printf("  Column %d: %d\n",j+1,arr[i][j]);
			}
		}
	}

	return 0;
}

