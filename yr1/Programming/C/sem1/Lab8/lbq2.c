#include <stdio.h>
#define ROW 2
#define COL 3

main(){
	
	int arr[ROW][COL];
	int i,j,small,big,total,aver;
	
	//read in values
	for(i=0;i<ROW;i++){
		printf("\nRow %d:\n",(i+1));
		for(j=0; j<COL; j++){
			printf("Element %d:",(j+1));
			scanf("%d",&arr[i][j]);
			getchar();
		}
	}
	
	printf("\n[Press Enter]");
	getchar();
	
	//display values
	for(i=0;i<ROW;i++){
		printf("\nRow %d:\n",(i+1));
		for(j=0; j<COL; j++){
			printf("Element %d: %d\n",(j+1),arr[i][j]);
		}
	}
	
	printf("\n[Press Enter]");
	getchar();
	
	//find smallest
	small=arr[0][0];
	for(i=0;i<ROW;i++){
		for(j=0; j<COL; j++){
			if(arr[i][j]<small){
				small= arr[i][j];
			}
		}
	}
	printf("\nSmallest element is: %d\n",small);
	
	printf("\n[Press Enter]");
	getchar();
	
	//find biggest
	big=arr[0][0];
	for(i=0;i<ROW;i++){
		for(j=0; j<COL; j++){
			if(arr[i][j]>small){
				big= arr[i][j];
			}
		}
	}
	printf("\nBiggest element is: %d\n",big);
	
	printf("\n[Press Enter]");
	getchar();
	
	//getting average
	total=0;
	for(i=0;i<ROW;i++){
		for(j=0; j<COL; j++){
			total+=arr[i][j];
		}
	}
	aver=total/(ROW*COL);
	printf("\nAverage is: %d\n",aver);
}
