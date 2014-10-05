#include <stdio.h>

void incBy1(int);

int main(){

	int num=1;
	printf("main(): num is %d\n",num);
	
	incBy1(num);
	
	printf("\nmain(): num is now %d\n",num);

	printf("\n[Press anykey to close]");
	//getchar();
	getchar();
	return 0;
}

void incBy1(int var){
	var++;
	printf("\nincBy1(): num is %d\n",var);	
}
