#include <stdio.h>

main(){
	FILE *fp;

	char filename[10];  //filename as char array
	
	printf("Please enter the filename you wish to open: ");
	gets(filename);  //read filename from user
	
	fp=fopen(filename,"r");
	
	if(fp==NULL){
		printf("\n\n Error: File cannot be opened");	
	}else{
		printf("\n\n File opened successfully\n\n");
		fclose(fp);
		printf("\n\n File has been now closed \n\n");
	}
}
