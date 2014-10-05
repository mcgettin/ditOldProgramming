#include <stdio.h>
#define MAX 256

int str2int(char str[], int max_size, int * success);

main(){

	char buffer[MAX];
	int ans=0,valid=0;

	printf("Please input a positive integer: ");
	fflush(stdout);
	fgets(buffer,MAX,stdin);
	buffer[strlen(buffer)-1]='\0';

	ans=str2int(buffer, MAX, &valid);

	if(valid==1){
		printf("\nValid int: %d\n",ans);
	}else{
		printf("\nInvalid Input\n");
	}

}


int str2int(char str[], int max_size, int * success){

	int num;
	int i;

	for(i=0; i<strlen(str); i++){
		if(str[i]=='\r'){
			str[i]='\0';
		}
	}

	for(i=0; str[i]!='\0'; i++){
		if(isdigit(str[i])){
			//printf("\nis num\n");
		}else{
			printf("\nFail\n");
			*success=0;
			return 0;
		}
	}
	printf("\nSuccess\n");
	
	*success=1;
	sscanf(str,"%d",&num);
	return num;
}
