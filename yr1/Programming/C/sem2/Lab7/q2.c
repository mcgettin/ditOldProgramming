#include <stdio.h>
#include <string.h>
#define SIZE 100

void noIs(char[]);
void noCh(char[]);
void appStr(char[]);

int main(){
	
	char sent[SIZE];
	
	printf("Please enter a sentence: ");
	fgets(sent,SIZE,stdin);

	noCh(sent);
	noIs(sent);
	appStr(sent);
	
	printf("\n[Press ENTER to close]");
	getchar();
	return 0;
}

void noIs(char arr[]){
	int isCt=0,i;

	for(i=0; arr[i+1]!='\0'; i++){
		if(arr[i]=='i' && arr[i+1]=='s'){
			isCt++;
		  }
	}
	printf("\"is\" occurs %d times in the sentence.\n",isCt);
}

void noCh(char arr[]){
	
	int i,chCt=0;
	for(i=0;arr[i]!='\0'; i++){
		chCt++;
	}
	printf("There are %d characters in the sentence.\n",chCt);
}

void appStr(char arr[]){
	
	char app[SIZE+20]="My sentence is: \0";
	strcat(app,arr);
	
	printf("Appended ==>  %s",app);
}

