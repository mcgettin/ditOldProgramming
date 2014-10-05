#include <stdio.h>

main(){
	
	int num1=15,num2=10;
	float result=0;
	
	//15+10
	result=num1+num2;
	printf("%d + %d = %f\n",num1,num2,result);
	
	//15-10
	result=num1-num2;
	printf("%d - %d = %f\n",num1,num2,result);
	
	//15*10
	result=num1*num2;
	printf("%d * %d = %f\n",num1,num2,result);
	
	//15/10
	result=num1/num2;
	printf("%d / %d = %f\n",num1,num2,result);
	
	//15%10
	result=num1%num2;
	printf("(%d / %d)[remainder] = %f\n",num1,num2,result);
}
