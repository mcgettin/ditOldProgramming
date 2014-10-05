#include <stdio.h>
#define SIZE 64

int main(){

	char arr[SIZE];
	FILE *fp;
	fp=fopen("text1.txt","rt");
	
	
	while(fgets(arr,SIZE,fp)!=NULL){
		if(strstr(arr,"school")!=NULL){
			printf("%s\n",arr);
		}
	
	}
	
	printf("\n[Press ENTER to close]");
	getchar();
	fclose(fp);
	return 0;
}
