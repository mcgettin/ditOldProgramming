#include <stdio.h>

int isOdd(int);

int main(){

	int num,odd;
	
	printf("Please insert number: ");
	scanf("%d",&num);
	
	odd=isOdd(num);
	
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

int isOdd(int var){

	if(var%2==0){
		return 0;
	}
	
	return 1;
}
