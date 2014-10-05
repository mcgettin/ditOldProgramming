#include <stdio.h>
#define SIZE 5

int oddElms(int[]);

int main(){

	int arr[SIZE],i,odds;
	
	printf("Please input %d integers for arr[]:\n",SIZE);
	for(i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
	
	odds=oddElms(arr);
	printf("\nTotal number of odd elements: %d\n",odds);
	
	getchar();
	getchar();
	return 0;
}

int oddElms(int nums[]){
	int i,odd=0;
	
	for(i=0;i<SIZE;i++){
		printf("\nElement %d: %d ",i+1,nums[i]);
		if(nums[i]%2==0){
			printf("is even\n");
		}else{
			printf("is odd\n");
			odd++;
		}
	}
	return odd;
}
