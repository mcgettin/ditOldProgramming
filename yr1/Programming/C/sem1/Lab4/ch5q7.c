#include <stdio.h>

main(){

	
	char num;
	
	printf("Please input a number from 1-7: ");
	scanf("%1s", &num);
	
	switch(num){
		case '1':
		printf("Sunday");
		break;
		case '2':
		printf("Monday");
		break;
		case '3':
		printf("Tuesday");
		break;
		case '4':
		printf("Wednesday");
		break;
		case '5':
		printf("Thursday");
		break;
		case '6':
		printf("Friday");
		break;
		case '7':
		printf("Saturday");
		break;
		default:
		printf("That's not a valid input!");
	}

}
