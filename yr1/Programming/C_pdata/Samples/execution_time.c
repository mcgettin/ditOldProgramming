#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	
	int i;
	clock_t begin, end;
	double time_spent;

	begin = clock();
	
	for(i=0;i<10000;i++){
		for(i=0;i<10000;i++){
			i+=1;
			i-=1;
		}
		i+=1;
		i-=1;
	}
	
	end = clock();
	
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%lf", time_spent);
	printf("\n[Press any key to close]");
	getchar();
	return 0;
}
