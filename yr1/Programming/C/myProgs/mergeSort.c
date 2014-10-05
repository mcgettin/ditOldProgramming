#include <stdio.h>
#define MAX 50


void partition(int arr[],int low,int high);
void mergeSort(int arr[],int low,int mid,int high);

int main(void){
	
	int i,arr[]={9,2,6,5,8,1,7,4,3,12,55,98,22,30,\
				0,14,87,59,33};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	printf("Unsorted: ");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	partition(arr,0,size-1);
	
	printf("\n\nSorted:   ");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	
	getchar();
	return 0;
}

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
	printf("\n");
	for(i=0;i<=high;i++){
		printf("%d ",arr[i]);
	}
}