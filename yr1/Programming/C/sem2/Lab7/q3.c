#include <stdio.h>
#include <string.h>
#define SIZE 32

int main(){
	
	char str1[SIZE],str2[SIZE];
	int comp;
	
	printf("Input a word for str1: ");
	fgets(str1,SIZE,stdin);

	printf("\nInput a word for str2: ");
	fgets(str2,SIZE,stdin);

	comp=strcmp(str1,str2);
	
	if(!comp){
		printf("\nThe strings str1 and str2 are equal.\n");
	}else{
		printf("\nThe strings str1 and str2 are not equal.\n");
	}
	
	printf("\n[Press ENTER to close]");
	getchar();
	return 0;
}
