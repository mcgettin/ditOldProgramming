#include <stdio.h>

main(){
	FILE *fp;
	
	fp=fopen("prog1.c","r"); //opening previous .c file
	
	//if file can't be opened...
	if(fp==NULL){
		printf("\n\n Error: File cannot be opened");	
	}else{ //else if all goes well
		printf("\n\n File opened successfully\n\n");
		fclose(fp);
		printf("\n\n File has been now closed \n\n");
	}
}
