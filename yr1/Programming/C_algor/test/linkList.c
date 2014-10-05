#include <stdio.h>

struct link{
	int data;
	struct link *pNext;
};
	
struct link *makeList(int);
void addNode(struct link*, int);
struct link *removeNode(struct link*,int);
struct link *removeList(struct link*);
void printList(struct link*);
int findNode(struct link *top, int num);
struct link *sortList(struct link*);

int main(){
	
	struct link *head=NULL;
	int choice=-1, num;
	
	while(choice!=0){
		if(head==NULL){
			printf("\nMenu:\n(1) Make New List\n(0) Exit program\n\n--->");
			scanf("%d",&choice);
			if(choice){
				printf("Enter head node value: ");
				scanf("%d",&num);
				head=makeList(num);
			}else if(!choice){
			
			}else{
				printf("Please submit a valid input\n");
			}
		}else{
			printf("\nPlease choose an option:\n(1) Add a Node\
					\n(2) Remove List\n(3) Remove a Node\n(4) Find a Node\n(5) Print the List\
					\n(6) Sort List\n(0) Exit the program\n\n---> ");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					printf("Enter new Node value: ");
					scanf("%d",&num);
					addNode(head,num);
					break;
				case 2:
					head=removeList(head);
					break;
				case 3:
					printf("Remove Node of value: ");
					scanf("%d",&num);
					head=removeNode(head,num);
					break;
				case 4:
					printf("Find Node of value: ");
					scanf("%d",&num);
					if(findNode(head,num)){
						printf("Node exists\n");
					}else{
						printf("Node not found\n");
					}
					break;
				case 5:
					printList(head);
					break;
				case 6:
					head=sortList(head);
					break;
				case 0:
					break;
				default:
					printf("Please enter a valid input\n");
			}
		}
	}
	if(head!=NULL){
		head=removeList(head);
	}
	printf("\n[Press ENTER to close]");
	getchar();
	getchar();
	return 0;
}

struct link *makeList(int num){

	//printf("Making first node of List with data: %d\n",num);
	
	struct link *pLink=(struct link*)malloc(sizeof(struct link));
	if(pLink==NULL){
		printf("-Failed to allocate memory for starting link-\n");
		return NULL;
	}
	pLink->data=num;
	pLink->pNext=NULL;
	
	return pLink;
}

void addNode(struct link *top, int num){
	
	if(findNode(top,num)){
		printf("\n-%d already exists in List-\n");
		return;
	}
	
	struct link *pLink=top;
	while(pLink->pNext!=NULL){
		pLink=pLink->pNext;
	}
	pLink->pNext=(struct link*)malloc(sizeof(struct link));
	if(pLink==NULL){
		printf("-Failed to add a node with value %d-",num);
		return;
	}else{
		printf("\nAdded %d to List\n",num);
	}
	
	pLink=pLink->pNext;
	pLink->data=num;
	pLink->pNext=NULL;
}

struct link *removeNode(struct link *top,int num){
	if(!findNode(top,num)){
		printf("Cannot delete non-existant node\n");
	}else if(top->pNext==NULL){
		printf("-Only node left, use Remove List instead-\n");
		return top;
	}
	struct link *node=top,*next=top->pNext;
	
	
	if(node->data==num){
		printf("-removed node-");
		node->data=next->data;
		node->pNext=next->pNext;
		free(next);
		return node;
	}
	while(next->pNext!=NULL){
		if(next->data==num){
			printf("-removed node-");
			node->pNext=next->pNext;
			free(next);
			node=top;
			return node;
		}
		node=next;
		next=next->pNext;
	}
	free(next);
	node->pNext=NULL;
	node=top;
	return node;
}

struct link *removeList(struct link *top){
	
	if(top==NULL){
		printf("\n-No List to remove-\n");
		return NULL;
	}
	printf("\nRemoving List\n");
	struct link *node=top;
	
	while(node->pNext!=NULL){
		top=node->pNext;
		printf("freed node with value %d\n",node->data);
		free(node);
		node=top;
	}
	printf("freed node with %d\n",node->data);
	free(node);	
	return NULL;
}

void printList(struct link *top){
	
	if(top==NULL){
		printf("\n-List not found-\n");
		return;
	}
	
	struct link *node=top;
	
	printf("\nList Contains:\n");
	while(node->pNext!=NULL){
		printf("%d, ",node->data);
		node=node->pNext;
	}
	printf("%d\n",node->data);
}

int findNode(struct link *top, int num){
	struct link *node=top;
	while(node!=NULL){
		if(node->data==num){
			return 1;
		}
		node=node->pNext;
	}
	return 0;
}


struct link *sortList(struct link *top){
	struct link *prev,*cur,*next;
	int done=0;
	
	cur=top;
	next=cur->pNext;

	while(!done){
		done=1;
		if(cur->data > next->data){
			done=0;
		
			cur->pNext=next->pNext;
			next->pNext=cur;
			top=next;
			
			prev=top;
			cur=top->pNext;
			next=cur->pNext;
		}else{
			prev=cur;
			cur=cur->pNext;
			next=cur->pNext;
		}
		
		while(cur->pNext!=NULL){
			if(cur->data > next->data){
				done=0;
			
				prev->pNext=cur->pNext;
				cur->pNext=next->pNext;
				next->pNext=cur;
				
				prev=next;
				next=cur->pNext;
			}else{
				prev=cur;
				cur=cur->pNext;
				next=cur->pNext;
			}
		}
		cur=top;
		next=cur->pNext;
	}
	
	return cur;
}


