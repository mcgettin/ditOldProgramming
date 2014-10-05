#include <stdlib.h>
#include <stdio.h>
#define SIZE 64

main()
{
	FILE * filer;
	char buffer[SIZE]; // used to read the data, size 100 bytes
	// Open the source file for reading
	int ct=0;

	if((filer=fopen("database.dat","rb"))==NULL){
		fprintf(stderr, "open read file error.\n");
		exit(1);
	}

	while(feof(filer)==0){	      // while not end of file for the source file
		fread(buffer,1,SIZE,filer);   	//read 100 bytes
		fwrite(buffer,1,SIZE,stdout);   //write 100 bytes
		printf("\n");
		ct++;
	}	
	printf("\ncount: %d",ct);
	puts("\n\n[Hit ENTER to close]");
	getchar();
	fclose(filer);
	return 0;
}
