#include <stdio.h>


int main(){
	
	char *text="abcd";
	char *p=text;
	p+=strlen(p)-1;
	while(text<=p){
		puts(p--);
	}
	
	printf("\n[Press Enter to close]");
	getchar();
	return 0;
}
