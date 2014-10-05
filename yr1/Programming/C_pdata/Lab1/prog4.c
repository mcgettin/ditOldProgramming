#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	FILE *fp;
	char ch;
	
	fp=fopen("prog1.c","r");
	
	if(fp==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	
	while((ch=fgetc(fp))!=EOF){
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}

