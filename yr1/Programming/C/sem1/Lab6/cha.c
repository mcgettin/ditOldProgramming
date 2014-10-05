#include <stdio.h>
#define SIZE 5

main(){
	
	int i;
	char charr[SIZE];
	printf("Please insert 5 characters:\n");
	for(i=0; i<SIZE; i++){
		scanf("%c",&charr[i]);
		getchar();
	}
	for(i=0; i<SIZE; i++){
		printf("charr[%d]: %c\n",i,charr[i]);
	}
	
}
