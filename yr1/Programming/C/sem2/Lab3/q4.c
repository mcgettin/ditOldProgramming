#include <stdio.h>
#define SIZE 10

char topCh(char[]);

int main(){

	int i;
	char ch[SIZE],hiC;
	
	printf("Please input %d chars:\n",SIZE);
	for(i=0; i<SIZE; i++){
		scanf("%c",&ch[i]);
		getchar();
	}

	hiC=topCh(ch);
	if(hiC=='\0'){
		printf("\nThere is no character that is most common\n");
	}else{
		printf("\nThe most common character is: %c\n",hiC);
	}
		
	printf("\n[Press any key to close]");
	getchar();
	return 0;
}

char topCh(char cha[]){
	int nCh[SIZE]={0},i,j,tally=0;
	char topC;
	
	for(i=0;i<SIZE;i++){
		for(j=i; j<SIZE;j++){
			if(cha[i]==cha[j]){
				nCh[i]++;
			}
		}
	}
	
	for(i=0;i<SIZE;i++){
		if(nCh[i]>tally){
			tally=nCh[i];
			topC=cha[i];
		}
	}
	if(tally==1){
		topC='\0';
	}
	return topC;
}
