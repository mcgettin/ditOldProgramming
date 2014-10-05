#include <stdlib.h>
#include <stdio.h>
//#define SIZE 64

struct record{
	char title[64];
	char author[64];
	float price;
	short year;
};
typedef struct record type_book;
int main()
{
	FILE * filer;
	type_book book;
	//char buffer[SIZE]; // used to read the data, size 100 bytes
	// Open the source file for reading

	if((filer=fopen("database.dat","rb"))==NULL){
		printf("open read file error.\n");
	
	}
	int i = 0;
	while(feof(filer)==0){	      // while not end of file for the source file
		i = fread(&book,sizeof(type_book),1,filer);   	//read 100 bytes
		//fwrite(&book,sizeof(book),1,stdout);   //write 100 bytes
		if (i == 1)
		{
		printf("Book:\n");
		printf("Title: %s\n",book.title);
		printf("Author: %s\n",book.author);
		printf("Price: $%.2f\n",book.price);
		printf("Year: %d\n",book.year);
		puts("\n");
		}
		
	}
	puts("\n[Hit ENTER to close]");
	getchar();
	fclose(filer);
	return 0;
}
