#include <stdio.h>

main()
{
	FILE * f;
	int i ;
	int buffer[10];
	int numr=0;
	int counter =0;
	
	if((f=fopen("numbers.bin","rb"))==NULL){
		printf( "open read file error.\n");
		exit(1);
	}
	//reading the file
	while(feof(f)==0){	  
		numr = fread(&i,sizeof(int),1,f);     
		//we need to check all the array!!
		   if ((i > 10) && (numr==1)) //numr=1 for ONE INSTANCE of
		   	{						 //a number
			printf("Num: %i \n",i);
			counter++;
			}
		}
	printf("The number of numbers above 10 is: %i \n", counter);
	fclose(f);	
	
	printf("\n\n[Press enter to quit]");
	getchar();
	return 0;
}
