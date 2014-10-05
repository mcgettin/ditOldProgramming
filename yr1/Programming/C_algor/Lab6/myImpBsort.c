#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble sort algorithm
void bubbleSort(int numbers[], int array_size);


int main()   // main program to test the algorithm
{
	srand(time(NULL));

	int i, myarray[2400];
	int n=2400;

	for(i=0;i<n;i++){
		myarray[i]=(rand()%(n*2))+1;
	}

	printf("N = %d\n\nArray is:\n",n);
	for(i=0; i<n;i++){
		printf("%d ",myarray[i]);
	}


	// Call the Bubble sort algorithm (pass variables myarray, and n)
	bubbleSort(myarray, n);

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
	int i, j, temp,done=0,pass=0;
	unsigned long comp=0,swap=0;
	puts("\n");
	
	//for loop exits when i=0 or when no swaps have been made
	for (i = (array_size - 1); i >0 && done==0; i--)     // pass number (last index of array to sort)
	{	
		pass++;
		done=1;
		
		for (j = 0; j <= i; j++)
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
	printf("Passes: %d\nComparisons: %lu\nSwaps: %lu",pass,comp,swap);
}

