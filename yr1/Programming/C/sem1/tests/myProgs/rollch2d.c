#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){

	srand(time(NULL));
	unsigned short d1,d2,roll;
	unsigned long i, MAX;
	double count[13];
	memset(count, '0', sizeof(count));
	
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
	
	printf("\nPercentage dice roll chance (two dice, %ld rolls):\n\n",MAX);

	for(i=0; i<MAX; i++){

		d1=(rand()%6)+1;
		d2=(rand()%6)+1;

		roll=d1+d2;
		//printf("Roll: %d\n", roll);

		switch(roll){
			case 2:
				count[2]=count[2]+1;
				break;
			case 3:
				count[3]=count[3]+1;
				break;
			case 4:
				count[4]=count[4]+1;
				break;
			case 5:
				count[5]=count[5]+1;
				break;
			case 6:
				count[6]=count[6]+1;
				break;
			case 7:
				count[7]=count[7]+1;
				break;
			case 8:
				count[8]=count[8]+1;
				break;
			case 9:
				count[9]=count[9]+1;
				break;
			case 10:
				count[10]=count[10]+1;
				break;
			case 11:
				count[11]=count[11]+1;
				break;
			case 12:
				count[12]=count[12]+1;
				break;
			default:
				printf("Roll Error.");
				getchar();
				break;
		}
	}
	for(i=2; i<13; i++){
		printf("Roll %hd:   %.2lf%%\n",i,((count[i]/MAX)*100));
	}

}
