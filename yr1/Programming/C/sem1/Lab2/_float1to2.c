#include <stdio.h>

main(){
	
	float count=0.0;
	int nums=0;
	float i=1;
	
	while(i<2.1){
		count+=i;
		i+=0.1;
		nums++;
	}
	printf("The average of the numbers from 1.0 to 2.0 by increments of 0.1 is: %f", (count/nums));
}
