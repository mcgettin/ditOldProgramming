#include <stdio.h>
#include <string.h>
#define MAX 50

struct link{
	int data;
	struct link *pNext;
};

struct link* push(struct link*, int);
struct link* pop(struct link*,int*);
int isFull(struct link*);

int expValid(char*);

int main(void){

	struct link *top=NULL;
	char str[MAX], use[MAX], *sub;
	int op1=0,op2=0;
	
	puts("Please input a string: ");
	fgets(str,MAX-1,stdin);
	
	strcpy(use,str);

	if(!expValid(use)){
		puts("\nInvalid expression\n");
		puts("\n[Press ENTER to close]");
		getchar();
		exit(1);
	}
	
	strcpy(use,str);
	sub=strtok(use," \n");
	while(sub!=NULL){
		//printf("\nsub: %s\n",sub);
		if(strcmp(sub,"*")==0 || strcmp(sub,"/")==0 || strcmp(sub,"+")==0 || strcmp(sub,"-")==0){
			top=pop(top,&op2);
			//printf("\npopping: %d",op2);
			top=pop(top,&op1);
			//printf("\npopping: %d\n",op1);
			switch(sub[0]){
				case '*':
					op1=op1*op2;
					top=push(top,op1);
					break;
				case '/':
					op1=op1/op2;
					top=push(top,op1);
					break;
				case '+':
					op1=op1+op2;
					top=push(top,op1);
					break;
				case '-':
					op1=op1-op2;
					top=push(top,op1);
					break;	
				default: 
					break;
			}
		}else{
			top=push(top,atoi(sub));
			//printf("\npushing: %d\n",atoi(sub));
		}
		sub=strtok(NULL," \n");
	}
	top=pop(top,&op1);
	printf("\nAnswer is: %d\n",op1);
	
	
	puts("\n[Press ENTER to close]");
	getchar();
	return 0;
}

int expValid(char * exp){
	char *tok;
	int tally=0;
	
	tok=strtok(exp," \n");
	while(tok!=NULL){
		if(strcmp(tok,"*")==0 || strcmp(tok,"/")==0 || strcmp(tok,"+")==0 || strcmp(tok,"-")==0){
			tally--;
			//printf("tally--: %d\n",tally);
		}else if(atoi(tok)!=0){
			tally++;
			//printf("tally++: %d\n",tally);
		}else{
			printf("error: contains unknown symbols");
			return 0;
		}
		
		if(tally<1){
			printf("error: not a valid RPN expression\n");
			return 0;
		}
		tok=strtok(NULL," \n");
	}
	
	if(tally==1){
		return 1;
	}
	
	puts("error: not a valid RPN expression\n");
	return 0;
}

struct link * push(struct link * head, int num){
	if(head==NULL){
		head=(struct link*)malloc(sizeof(struct link));
		head->data=num;
		head->pNext==NULL;
		//printf("pushing first: %d\n",head->data);
		return head;
	}
	if(isFull(head)){
		printf("\nStack is full\n");
		return head;
	}
	struct link *pLink=(struct link*)malloc(sizeof(struct link));
	
	pLink->data=num;
	pLink->pNext=head;
	
	head=pLink;
	//printf("pushing: %d\n",head->data);
	return head;
}

struct link * pop(struct link * head, int * val){
	if(head==NULL){
		printf("\nStack is empty\n");
		*val=-1;
		return head;
	}

	*val=head->data;
	
	struct link *pLink=head;
	if(head->pNext==NULL){
		head=NULL;
	}else{
		head=head->pNext;
		free(pLink);
		pLink=NULL;
	}
	return head;
}

int isFull(struct link* head){
	
	struct link * pLink=head;
	int tally=0;
	
	while(pLink!=NULL){
		tally++;
		pLink=pLink->pNext;
		
	}
	if(tally<8){
		return 0;
	}
	return 1;
	
}

