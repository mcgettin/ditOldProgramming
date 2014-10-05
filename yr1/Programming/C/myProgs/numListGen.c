#include <stdio.h>
#include <stdlib.h>
#define MAX 500

int main(void){

	int i;
	char sNum[8];
	FILE * fp;
	
	fp=fopen("nums.txt","wt");
	
	for(i=0; i<MAX; i++){
		itoa(i+1,sNum,10);
		fputs(sNum,fp);
		fputs(" ",fp);
	}
	
	close(fp);
	return 0;
}
