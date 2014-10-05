#include <stdio.h>


int main(){
	
	int i;
	char name[12];
	
	printf("Please input first name: ");
	gets(name);
	
	for(i=0;name[i]!='\0';i++){
		printf("%c ",name[i]);
	}
	
	printf("\n\n[Press Enter to close]");
	getchar();
	return 0;
}
