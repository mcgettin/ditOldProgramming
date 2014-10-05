#include <stdio.h>

main(){

	float s1,s2,s3;
	
	printf("Please input the 3-sides of your triangle:\n");
	scanf("%f %f %f", &s1,&s2,&s3);
	
	if((s1+s2)<s3){
		printf("This 'triangle' is invalid!");	
	}else if((s2+s3)<s1){
		printf("This 'triangle' is invalid!");
	}else if((s1+s3)<s2){
		printf("This 'triangle' is invalid!");
	}else{
		printf("Nice triangle, bro.");
	}
}
