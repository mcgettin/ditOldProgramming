#include <stdio.h>

void isOdd(int, int*);

int main(){

	int num,odd;
	
	printf("Please insert number: ");
	scanf("%d",&num);
	
	isOdd(num,&odd);
	
	if(odd){
		printf("\n%d is Odd\n",num);
	}else{
		printf("\n%d is Even\n",num);
	}
	
	printf("\n[Press any key to close]");
	getchar();
	getchar();
	return 0;
	
}

void isOdd(int var,int * odnum){

	if(var%2==0){
		*odnum=0;
	}else{
		*odnum=1;
	}
}
