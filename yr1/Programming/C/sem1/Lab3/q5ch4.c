#include <stdio.h>
#define HB 75
#define year 365
#define day 24
#define hour 60

//q5,chapter4

main(){
	
	unsigned int age;
	long totBeats=0;
	
	printf("Please input your age:\n");
	scanf("%d",&age);
	totBeats=(long)(age*year*day*hour*HB);
	
	printf("Your heart has beat about %lu times in your lifetime!", totBeats);
	
}
