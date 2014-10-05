#include <stdio.h>

void repChar(char, int);

int main(){

	int n;
	char c;

	printf("Please input character to repeat: ");
	scanf("%c",&c);
	printf("Please input number of repititions: ");
	scanf("%d",&n);
	printf("\n");
	repChar(c,n);
	
	return 0;

}

void repChar(char ch, int num){
	
	int i;
	for(i=0; i<num; i++){
		printf("%c",ch);
	}
	printf("\n");

	
}
