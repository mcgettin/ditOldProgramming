#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 2

int main(){
	
	int i,j,arr[ROW][COL],tally;
	
	//read in values for arr[][]
	printf("Please input %d elements for 'arr':\n",ROW*COL);
	for(i=0;i<ROW;i++){
		printf("Row %d:\n",i+1);
		for(j=0; j<COL;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	//total each row
	for(i=0;i<ROW;i++){
		tally=0;
		for(j=0; j<COL;j++){
			tally+=arr[i][j];
		}
		printf("Sum of Row %d: %d\n",i+1,tally);
	}
	
	//total each column
	for(i=0;i<COL;i++){
		tally=0;
		for(j=0; j<ROW;j++){
			tally+=arr[j][i];
		}
		printf("Sum of Column %d: %d\n",i+1,tally);
	}
	
	//Highest element
	tally=arr[0][0];
	for(i=0;i<ROW;i++){
		for(j=0; j<COL;j++){
			if(tally<arr[i][j]){
				tally=arr[i][j];
			}
		}
	}
	printf("Highest element is: %d\n",tally);
	
	return 0;
}

