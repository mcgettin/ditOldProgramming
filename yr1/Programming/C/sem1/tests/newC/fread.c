#include <stdio.h>
#define MAX 64

main(){
	
	FILE *fp;
	int i;
	fp=fopen("tfile.txt", "r");
	char ch='y';
	char str[MAX];
	char *pc=&ch;
	
	while(ch!='n'){
	if(feof(fp)){
		ch='n';
		printf("\nEnd of File\n");
	}else{
	printf("\nRead next MAX chars from file? (y/n): ");
	gets(pc);
	switch(ch){
	  case 'y':{
		if(fp){
			fgets(str, MAX, fp);
			for(i=0; i<strlen(str); i++){
				if(str[i]=='\r'){
					str[i]='\0';
				}
			}
			printf("line: %s\n", str);
		}else{
			printf("-File Read Error-\n");
		}
		break;
	  }
	  case 'n':{
		printf("\nUser Quit\n");
		break;
	  }
	  default:{
		printf("\nInvalid input.\n");
	  }	  
	}
	}
	}
	printf("\nProgram End\n");
	fclose(fp);
}
