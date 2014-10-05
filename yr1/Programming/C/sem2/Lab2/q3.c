#include <stdio.h>

void loHi(int, int, int);

int main(){

	int num1,num2,num3;

	printf("Please input integers: \n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	scanf("%d",&num3);
	
	loHi(num1,num2,num3);
	
	return 0;
}

void loHi(int n1, int n2, int n3){
	
	int i,hi,low;
	
	hi=n1;
	if(n2>hi){
		hi=n2;
	}else if(n3>hi){
		hi=n3;
	}
	
	low=n1;
	if(n2<low){
		low=n2;
	}else if(n3<low){
		low=n3;
	}
	
	printf("\nThe highest value is: %d\n",hi);
	printf("\nThe lowest value is: %d\n",low);
}
