#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int lines=0;
	char ch;
	char filename[10];  //filename as char array
	
	printf("Please enter the filename you wish to open: ");
	gets(filename);  //read filename from user
	
	fp=fopen(filename,"r");
	
	if(fp==NULL){
		printf("\n\n Error: File cannot be opened");
		exit(1);	
	}
	printf("\n\n File opened successfully\n\n");
	
	while((ch=fgetc(fp))!=EOF){
		if(ch=='\n'){
			lines++;
		}
	}
	
	fclose(fp);
	printf("\n\n File has been now closed \n\n");
	
	printf("\nThere are %d lines in %s\n",lines,filename);
		
	return 0;
}
