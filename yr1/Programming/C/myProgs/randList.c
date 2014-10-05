#include <stdio.h>
#include <stdlib.h>

char * mkList(FILE * fp);

int main(void){

	FILE * fp;
	fp=fopen("nums.txt","r+");
	fseek(fp,0,SEEK_SET);
	
	char c;
	int list[0],i;
	
	while(!feof(fp)){
		c=fgetc(fp);
		printf("\nc:%c",c);
		if(c!=' '){
			realloc(list,sizeof(int));
			list[sizeof(list)/sizeof(int)-1]=(int)c;
			printf("\noutput:");
			for(i=0;i<(sizeof(list)/sizeof(int));i++){
				printf("%d",list[i]);
			}
		}
		getchar();
	}
	
	//char list[]=mkList(fp);
	
	
	close(fp);
	printf("end.");
	getchar();
	return 0;
}

char * mkList(FILE * fp){
	rewind(fp);
	
	while(!eof(fp)){
		
	}
	
	return 0;
}
