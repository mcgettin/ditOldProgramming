#include <stdio.h>

main(){

	int num=0;
	while(num<1){
		printf("Please insert a positive integer: ");
		scanf("%d",&num);
	}
	while(num!=1){
		if(num%2==0){
			num=num/2;
		}else{
			num=(num*3)+1;
		}
		printf("%d\n",num);
	}
	getchar(); 
	getchar();
}
