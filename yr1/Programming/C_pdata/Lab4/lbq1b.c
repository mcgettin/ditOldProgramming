#include <stdio.h>

main()
{
	FILE * f;
	int i ;
	int buffer[10];
	int numr =0;
	int odd=0,even=0;
	
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
		   if (buffer[i]%2==1) 
		   {
			odd++;
		   }else{
			even++;
		   }
		}
	}
	printf("There are %d odd and %d even numbers\n",odd,even);
	fclose(f);	
	printf("\n\n[Hit ENTER to close]");
	getchar();
	return 0;
}
