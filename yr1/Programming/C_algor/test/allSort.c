#include <stdio.h>
#include <stdlib.h>
#define MAX 40

void bubbleSort(int arr[]);
void impBubSort(int arr[]);
void selectSort(int arr[]);
void insertSort(int arr[]);
void quickSort(int arr[],int low,int high);

int main(void){

	srand(time(NULL));
	
	int i, list[MAX];
	
	for(i=0;i<MAX;i++){
		list[i]=(rand()%MAX)+1;
	}
	
	/*
	printf("Array unsorted:\n");
	for(i=0; i<MAX;i++){
		printf("%d ",list[i]);
	}
	*/
	
	//bubbleSort(list);
	//impBubSort(list);
	//selectSort(list);
	//insertSort(list);
	//quickSort(list,0,MAX-1);
	
	/*
	printf("\n\nArray sorted:\n");
	for(i=0; i<MAX;i++){
		printf("%d ",list[i]);
	}
	*/
	
	printf("\n\n[Please press ENTER to close]");
	getchar();
	return 0;
}


void bubbleSort(int arr[]){
	
	int i, j, temp;
	int pass=0, comp=0, swap=0;
	
	for(i=MAX-1; i>0; i--){
		pass++;
		for(j=0; j<i; j++){
			comp++;
			if(arr[j]>arr[j+1]){
				swap++;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			
			}
			
		}
	}
	printf("\n\nBubble Sort:\n");
	printf("Passes: %d\nComparisons: %d\nSwaps: %d\n",pass,comp,swap);
}

void impBubSort(int arr[]){
	
	int i, j, temp, done;
	int pass=0, comp=0, swap=0;
	
	for(i=MAX-1; i>0; i--){
		pass++;
		done=1;
		for(j=0; j<i; j++){
			comp++;
			if(arr[j]>arr[j+1]){
				swap++;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				done=0;
			
			}
			
		}
		if(done){
			printf("\n\nImproved Bubble Sort:\n");
			printf("Passes: %d\nComparisons: %d\nSwaps: %d\n",pass,comp,swap);
			return;
		}
	}
	printf("\n\nImproved Bubble Sort:\n");
	printf("Passes: %d\nComparisons: %d\nSwaps: %d\n",pass,comp,swap);
}

void selectSort(int arr[]){

	int i, j, temp, min;
	int pass=0, comp=0, swap=0;
	
	for(i=0; i<MAX-1;i++){
		pass++;
		min=i;
		for(j=i+1; j<MAX;j++){
			comp++;
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
		swap++;
	}
	printf("\n\nSelection Sort:\n");
	printf("Passes: %d\nComparisons: %d\nSwaps: %d\n",pass,comp,swap);
}

void insertSort(int arr[]){

	int i, j, curr;
	int pass=0, comp=0, swap=0;
	
	for(i=1;i<MAX;i++){
		pass++;
		curr=arr[i];
		j=i;
		comp++;
		while((j>0) && (arr[j-1]>curr)){
			swap++;
			arr[j]=arr[j-1];
			j=j-1;
		}
		arr[j]=curr;
	}
	printf("\n\nInsertion Sort:\n");
	printf("Passes: %d\nComparisons: %d\nSwaps: %d\n",pass,comp,swap);
}

void quickSort(int arr[],int low,int high){

	int pivot,j,temp,i;
	
	if(low<high){
		pivot = low;
		i = low;
		j = high;
 
		while(i<j){
			while((arr[i]<=arr[pivot])&&(i<high)){
				i++;
			}
 
			while(arr[j]>arr[pivot]){
				j--;
			}
 
			if(i<j){ 
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
 
		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
	
		quickSort(arr,low,j-1);
		quickSort(arr,j+1,high);
	}
}
