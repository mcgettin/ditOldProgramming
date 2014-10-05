#include <stdio.h>
//program to open and close a file
main(){
	FILE *fp; //file pointer
	
	fp=fopen("prog1.c","r");  // "r" for read
	fclose(fp);  // release/close program
}

