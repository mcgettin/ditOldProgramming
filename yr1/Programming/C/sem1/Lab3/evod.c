#include <stdio.h>

//Program to get number from user and check if it's even or odd.

main(){
	
	int num=0;
	while(num<1 || num>100){
		printf("Please insert number between 1 and 100:\n");
		scanf("%d", &num); //getting a number
	}
	if(num%2==1){
		printf("Your number %d is an odd number",num);
	}else{
		printf("Your number %d is an even number",num);
	}
}
