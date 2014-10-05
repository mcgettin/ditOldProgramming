#include <stdio.h>

main(){

	int num,divis;
	
	printf("Please input two integers to divide:\n");
	scanf("%d %d",&num,&divis);
	
	printf("Quotient= %d\tRemainder= %d\n   ----\n%d | %d\n",(num/divis),(num%divis),divis,num);
	
}
