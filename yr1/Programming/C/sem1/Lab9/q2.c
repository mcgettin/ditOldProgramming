#include <stdio.h>
#define ROW 4
#define COL 6

int main(){
	
	int data[ROW][COL]= {{3,2,5,7,4,2},{1,4,4,8,13,1},{9,1,0,2,0,0},{0,2,6,3,-1,-8}};
	int sum=0;
	int i,j;
	
	for(i=0; i<ROW; i++){
		for(j=0; j<COL;j++){
			sum+=data[i][j];
		}
	}
	printf("Data:\n");
	for(i=0; i<ROW; i++){
		printf("Row%d:\n",i+1);
		for(j=0; j<COL;j++){
			printf("Col%d: %d\n",j+1,data[i][j]);
		}
	}
	printf("\nSum: %d\n",sum);
	return 0;
}

