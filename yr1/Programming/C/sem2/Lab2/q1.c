#include <stdio.h>

void tenStar(void);

int main(){

	printf("\n");
	tenStar();
	
	return 0;
}

void tenStar(){
	
	int i;
	for(i=0; i<10; i++){
		printf("*");
	}
	printf("\n");

}
