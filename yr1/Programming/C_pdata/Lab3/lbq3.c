#include <stdio.h>
#define SIZE 512

int main(){
	
	int nr1,nr2,nw;
	char buffer[SIZE];
	
	FILE *fp1,*fp2,*fpOut;
	fp1=fopen("file2.bmp","rb");
	fp2=fopen("file3.bmp","rb");
	fpOut=fopen("picture.bmp","wb");
	
	while(!feof(fp1) && !feof(fp2)){
		nr1=fread(buffer,1,SIZE,fp1);
		nw=fwrite(buffer,1,nr1,fpOut);
		if(nw!=nr1){
			printf("Error in write command!\n");
			getchar();
			exit(1);
		}
		nr2=fread(buffer,1,SIZE,fp2);
		nw=fwrite(buffer,1,nr2,fpOut);
		if(nw!=nr2){
			printf("Error in write command!\n");
			getchar();
			exit(1);
		}
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fpOut);
	return 0;
}

