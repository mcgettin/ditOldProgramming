#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){

	srand(time(NULL));
	unsigned short roll, *die,si,no;
	unsigned long i,j, MAX;
	double *count;
	
	printf("Input desired accuracy (1-5 <--> (low-high)): ");
	scanf("%d",&MAX);
	getchar();
	
	switch(MAX){
		case 1:
			MAX=50;
			break;
		case 2:
			MAX=500;
			break;
		case 3:
			MAX =10000;
			break;
		case 4:
			MAX=500000;
			break;
		case 5:
			MAX=50000000;
			break;
		default:
			MAX=50;
			printf("Invalid input. Set to low.\n");					
	}
	
	printf("Please input number of dice to roll: ");
	scanf("%d",&no);
	getchar();
	
	printf("Please input number of sides on dice: ");
	scanf("%d",&si);
	getchar();
	

	die=(unsigned short *)calloc(no,sizeof(short));
	count=(double *)calloc((no*si),sizeof(double));
	
	printf("\nPercentage dice roll chance (%d dice(%d-sided), %ld rolls):\n\n",no,si,MAX);

	for(i=0; i<MAX; i++){
		
		roll=0;
		for(j=0; j<no; j++){
			*(die+j)=(rand()%si)+1;
			roll+=*(die+j);
		}
		//printf("\nroll is: %d\n",roll);
		for(j=0;j<(no*si)+1;j++){
			if(roll == j){
				//printf("adding to count\n");
				*(count+j)+=1;
			}
		}
	
	}
	
	for(i=no; i<(no*si)+1; i++){
		printf("Roll %hd:   %.2lf%%\n",i,((*(count+i)/MAX)*100));
	}
	
	free(die);
	free(count);
	getchar();
}
