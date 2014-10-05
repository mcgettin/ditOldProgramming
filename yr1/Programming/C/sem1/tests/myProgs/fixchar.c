//Program to read in chars and flush input buffer

#include <stdio.h>

int main(){

	char a, b, ch;
	printf("Please insert two chars:\n");
	scanf("%c",&a);
	while ((ch = getchar()) != '\n' && ch != EOF){};
	scanf("%c", &b);
	while ((ch = getchar()) != '\n' && ch != EOF){};
	printf("char a: %c\nchar b: %c\n",a,b);

	printf("[Press enter]\n");
	getchar();
	return 0;
}

