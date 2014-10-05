#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fPut,*fGet;
	fGet=fopen("myFile.txt","rt");
	fPut=fopen("myCopy.txt","wt");
	
	char c;
	
	while((c=fgetc(fGet))!=EOF){
		fputc(c,fPut);
		printf(". ");
	}
	
	
	fclose(fPut);
	fclose(fGet);
	return 0;
}

