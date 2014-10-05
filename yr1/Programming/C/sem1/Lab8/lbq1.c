#include <stdio.h>

main(){
	
	int a[10],i;
	
	for (i = 0; i < 10; i++){ 
		a[i] = 9 - i; 
    } 
    
	for (i = 0; i < 10; i++){ 
		a[i] = a[ a[i] ]; 
    } 
	
	for (i = 0; i < 10; i++){ 
		printf("a[%d]: %d\n",i,a[i]);
	}
}
