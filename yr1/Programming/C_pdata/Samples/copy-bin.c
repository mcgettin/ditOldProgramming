/*using fread() and fwrite() to copy files.*/
#include <stdlib.h>
#include <stdio.h>

main()
{
	FILE * filer;
	FILE * filew;
	int numr,numw;
	char buffer[100]; // used to read the data, size 100 bytes
	// Open the source file for reading
	if((filer=fopen("myCopy.bin","rb"))==NULL){
		fprintf(stderr, "open read file error.\n");
		exit(1);
	}

	// Open the destination file for writing
	if((filew=fopen("myCwrite.bin","wb"))==NULL){
		fprintf(stderr,"open write file error.\n");
		exit(1);
	}
	while(feof(filer)==0){	      // while not end of file for the source file
		numr=fread(buffer,1,100,filer);   	//read 100 bytes
		numw=fwrite(buffer,1,numr,filew);   //write 100 bytes
		if(numw!=numr){						//check if any error writing
			fprintf(stderr,"write file error.\n");
			exit(1);}
	}	
	fclose(filer);
	fclose(filew);
	return 0;
}
