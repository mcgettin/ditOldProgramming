#include <stdio.h>
#define SIZE 8

main(){
	
	int i, temp,srt, nums[SIZE];
	
	printf("Please insert %d integers:\n",SIZE);
	for(i=0; i<SIZE; i++){
		scanf("%d",&nums[i]);
	}
	
	srt=0;
	while(!srt){
		for(i=0;i<SIZE-1;i++){
			srt=1;
			if(nums[i]>nums[i+1]){
				temp=nums[i];
				nums[i]=nums[i+1];
				nums[i+1]=temp;
				srt=0;
				i=SIZE;
			}
		}
	}
	
	printf("In order:\n");
	for(i=0; i<SIZE; i++){
		printf("nums[%d]: %d\n",i,nums[i]);
	}
}

