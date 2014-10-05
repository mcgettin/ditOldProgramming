#include <stdio.h>

int main(){
	int count=0;
	int i;
	
	for(i=1; i<6;i++){
		count+=i;
	}
	printf("the sum of the numbers from 1 to 5 is %d", count);
}
