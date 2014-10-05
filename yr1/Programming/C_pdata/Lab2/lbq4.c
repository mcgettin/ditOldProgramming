/*using fread() and fwrite() to copy files.*/
#include <stdlib.h>
#include <stdio.h>
#define SIZE 50

main()
{
	FILE * filer;
	FILE * filew;
	int numr,numw;
	char buffer[SIZE]; // used to read the data, size 100 bytes
	// Open the source file for reading
	if((filer=fopen("myFile.txt","rb"))==NULL){
		fprintf(stderr, "open read file error.\n");
		exit(1);
	}

	// Open the destination file for writing
	if((filew=fopen("myCopy.txt","wb"))==NULL){
		fprintf(stderr,"open write file error.\n");
		exit(1);
	}
	while(feof(filer)==0){	      // while not end of file for the source file
		numr=fread(buffer,1,SIZE,filer);   	//read 100 bytes
		numw=fwrite(buffer,1,numr,filew);   //write 100 bytes
		printf(". ");
		if(numw!=numr){						//check if any error writing
			fprintf(stderr,"write file error.\n");
			exit(1);}
	}	
	fclose(filer);
	fclose(filew);
	return 0;
}
