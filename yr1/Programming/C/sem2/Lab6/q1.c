#include <stdio.h>


int main(){
	
	printf("%5s\n","abcd");
	printf("%5s\n","abcdef");
	printf("%-5s\n","abc");
	printf("%5.2s\n","abcde");
	printf("%-5.2s\n","abcde");
	
	printf("\n[Press Enter to close]");
	getchar();
	return 0;
}
