#include <stdio.h>

/*program to sum together numbers from 1 to 5*/

int main(){
	
	int count=0;
	int i;
	
	//loop from i=1 to i=5, adding i to count
	
	for(i=1; i<6;i++){
		count+=i;
	}
	
	printf("the sum of the numbers from 1 to 5 is %d", count);
}
