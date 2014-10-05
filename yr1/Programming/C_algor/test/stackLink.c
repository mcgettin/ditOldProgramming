#include <stdio.h>
#define MAX 8

struct link{
	int data;
	struct link *pNext;
};

struct link* push(struct link*, int);
struct link* pop(struct link*,int*);

int isFull(struct link*);

int main(){

	struct link *top=NULL;
	int num=0,menu=-1;
	
	while(menu!=0){
		
		printf("\nPlease Choose an option:\n");
		printf("(1) Push to Stack\n(2) Pop from Stack\n\n(0) Exit Program (empty stack)\n");
		printf("\n---> ");
		scanf("%d",&menu);
		
		if(menu==1){
			printf("\nPush what value?: ");
			scanf("%d",&num);
			top=push(top,num);
		
		}else if(menu==2){
			top=pop(top,&num);
			if(top!=NULL)	printf("popped: %d\n",num);
		
		}else if(menu==0){
			puts("\n");
			while(top!=NULL){	
				top=pop(top,&num);
				printf("%d\n",num);	  
			}
		
		}else{
			printf("\n-Invalid option-\n");
		
		}
	}
	
	printf("\n\[Press ENTER to close] ");
	getchar();
	getchar();
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

