#include <stdio.h>
#include <string.h>
#define SIZE 32

void noCh(char arr[]);

int main(){
	
	char str1[SIZE],str2[SIZE];
	char appC[SIZE+20]="First word entered is \0";
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
	
	strcat(appC,str1);
	printf("\n%s\n",appC);
	
	printf("\nlength of appC is %d\n",strlen(appC));
	noCh(appC);
	
	printf("\n[Press ENTER to close]");
	getchar();
	return 0;
}


void noCh(char arr[]){
	
	int i,chCt=0;
	for(i=0;arr[i]!='\0'; i++){
		chCt++;
	}
	printf("There are %d characters in appC.\n",chCt);
}
