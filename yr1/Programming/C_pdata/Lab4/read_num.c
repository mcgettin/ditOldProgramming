#include <stdio.h>

main()
{
	FILE * f;
	int i ;
	int buffer[10];
	int numr =0;
	int counter =0;
	
	if((f=fopen("numbers.bin","rb"))==NULL){
		printf( "open read file error.\n");
		exit(1);
	}
	//reading the file
	while(feof(f)==0){	  
		numr = fread(buffer,sizeof(int),10,f);     
		//we need to check all the array!!
		for (i=0; i<numr; i++)
		{
		   if (buffer[i] > 10) 
		   	{
			printf("Num: %i \n",buffer[i]);
			counter++;
			}
		}
	}
	printf("The number of numbers above 10 is: %i \n", counter);
	fclose(f);	
	getchar();
	return 0;
}
