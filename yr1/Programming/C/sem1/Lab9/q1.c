#include <stdio.h>
#define ROW 3
#define COL 4

main(){
	
	int arr1[ROW][COL]={{1,2,3,4},{5,6,7,8},{9,10,11,12}}; 
	int arr2[ROW][COL]={{21,22,23,24},{25,26,27,28},{29,30,31,32}};
	int arr3[ROW][COL];
	int i,j;
		
	for(i=0;i<ROW;i++){
		for(j=0; j<COL; j++){
			arr3[i][j]=arr1[i][j]*arr2[i][j];
		}
	}
	printf("\n\tArr3:\n");
	for(i=0;i<ROW;i++){
		printf("Row%d:\n", i+1);
		for(j=0; j<COL; j++){
			printf("Column%d: %d\n",(j+1),arr3[i][j]);
		}
	}
}
