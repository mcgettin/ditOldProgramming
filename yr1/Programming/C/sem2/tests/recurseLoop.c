#include <stdio.h>
#include <windows.h>
void resurse(int loop,int max);

int main(){
	
	int i=0,max;
	
	printf("Input custom maximum: ");
	scanf("%d",&max);
	fflush(stdin); // Flush the input buffer

	
	resurse(i,max);
	printf("\nDone!");
	getchar();
	return 0;
}

void resurse(int loop,int max){
	
	Sleep(1);
	printf("At loop: %d\n",loop+1);
	
	if (loop+1 < max) resurse(loop+1,max);
}