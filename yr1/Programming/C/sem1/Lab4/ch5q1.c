#include <stdio.h>

main(){

	char stat;
	
	printf("Please input marriage status\n(S=single, M=married, W=widowed, E=separated, D=divorced):");
	scanf("%c", &stat);
	
	switch(stat){
		case 'S':
		case 's':
			printf("You are Single.");
			break;
		case 'M':
		case 'm':
			printf("You are Married.");
			break;
		case 'W':
		case 'w':
			printf("You are Widdowed.");
			break;
		case 'E':
		case 'e':
			printf("You are Separated.");
			break;
		case 'D':
		case 'd':
			printf("You are Divorced");		
			break;
		default:
			printf("Invalid input.");
	}
}
