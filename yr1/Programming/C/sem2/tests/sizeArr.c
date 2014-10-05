#include <stdio.h>
#define SIZE 8

int main(){

	char arr[SIZE]="Hello";
	char arr2[SIZE]={'H','e','l','l','o'};

	printf("arr[] has size: %d\n%s.\n",sizeof(arr),arr);
	printf("arr2[] has size: %d\n%s.",sizeof(arr2),arr2);
	
	getchar();
	return 0;
}
