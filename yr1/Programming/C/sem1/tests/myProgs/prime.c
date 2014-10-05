#include <stdio.h>
#define MAX 13013

//Prime number program
int main(){

	int upTo=0,count=0;
	int i,j;
	char found;

	while(upTo<1 || upTo>MAX){
		printf("Calculate prime numbers up to [Enter integer]: ");
		scanf("%d",&upTo);
		getchar();
		printf("\n");
	}

	for(i=2; i<(upTo/2)+1 ;i++){

		for(j=i/2; j>1 && found; j--) if(i%j==0) continue;
				
		printf("prime: %d\n",i);
	}
	getchar();
	return 0;
}
