#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble sort algorithm
void bubbleSort(int[], int);
void impBsort(int[],int);

int main()   // main program to test the algorithm
{
	srand(time(NULL));

	int i, myarray[4000],myarray2[4000];
	int n=4000;
	
	for(i=0;i<n;i++){
		myarray[i]=(rand()%(n*2))+1;
		myarray2[i]=myarray[i];
	}
	
	printf("N = %d\nArray is:\n",n);
	for(i=0; i<n;i++){
		printf("%d ",myarray[i]);
	}


	// Call the Bubble sort algorithm (pass variables myarray, and n)
	bubbleSort(myarray, n);
	impBsort(myarray2,n);

	// print out the sorted array
	printf("\n\nSorted Array is: \n");
	for(i=0; i<n;i++){
		printf("%d ",myarray[i]);
	}
	
	
	printf("\n\n[Press Enter to close]");
	getchar();

	return 0;
}


void bubbleSort(int numbers[], int array_size)
{
	int i, j, temp,pass=0; //temp used for swaps, pass counts the array passes
	long comp=0,swap=0; //comp counts the comparisons, swap counts the swaps
	
	for (i = (array_size - 1); i>0; i--)     // pass number (last index of array to sort)
	{	
		pass++;
		/*
		puts("\n");
		for(j=0; j<array_size;j++){
		printf("%d ",numbers[j]);
		}
		*/
		for (j = 0; j < i; j++)
		{
			comp++;
			if (numbers[j]>numbers[j+1])    // ie,  (j-1)st number > j-th number
			{
				swap++;
				temp=numbers[j+1];
				numbers[j+1]=numbers[j];
				numbers[j]=temp;
			}
		}
	}
	//printing detailed info on the performance of the sorting algorithm
	printf("\n\n--Bubble Sort--\nPasses: %d\nComparisons: %lu\nSwaps: %lu",pass,comp,swap);
}

void impBsort(int numbers[], int array_size)
{
	int i, j, temp,done=0,pass=0;
	unsigned long comp=0,swap=0;
	
	//for loop exits when i=0 or when no swaps have been made
	for (i = (array_size - 1); i >0 && done!=1; i--)     // pass number (last index of array to sort)
	{	
		pass++;
		done=1;
		/*
		puts("\n");
		for(j=0; j<array_size;j++){
		printf("%d ",numbers[j]);
		}
		*/
		for (j = 0; j < i; j++)
		{
			comp++;
			if (numbers[j]>numbers[j+1])    // ie,  (j-1)st number > j-th number
			{
				swap++;
				temp=numbers[j+1];
				numbers[j+1]=numbers[j];
				numbers[j]=temp;
				done=0;
			}
		}
	}
	printf("\n\n--Improved Bubble Sort--\nPasses: %d\nComparisons: %lu\nSwaps: %lu",pass,comp,swap);
}



