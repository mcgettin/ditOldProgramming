#include <stdio.h>

main(){

	int num1,num2,mod;
	
	
	printf("Please input two integers:\n");
	scanf("%d %d",&num1,&num2);
	
	mod=num1%num2;
	
	if(mod!=0){
		printf("%d is not evenly divisible by %d", num1,num2);
	}else{
		printf("%d is evenly divisible by %d", num1,num2);
	}
}
