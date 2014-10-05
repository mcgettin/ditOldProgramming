#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int main(){

	FILE *fp;
	fp=fopen("myF.txt","rt");	
	char arr[MAX];
	
	while(fgets(arr,MAX,fp)!=NULL){
		printf("%s\n",arr);
	}
	
	
	fclose(fp);
	printf("\n\n[press Enter to close]");
	getchar();
	
	return 0;
}
