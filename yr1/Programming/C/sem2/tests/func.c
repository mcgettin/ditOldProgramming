#include <stdio.h>

int func(int,int);

main(){
	int num1=5, num2=8;
	func(num1,num2);
	
	printf("\n[Press any key to close]");
	getchar();
	
}

int func(int x, int y){
	printf("\nnum1: %d\nnum2: %d\n",x,y);
}

