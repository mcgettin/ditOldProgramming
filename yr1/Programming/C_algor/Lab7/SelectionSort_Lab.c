#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void selectionSort(int numbers[], int array_size);

int main()                          // main program to test the algorithm
{
	// Declare and initialise a simple array of size 100

	int myarray[SIZE];
	int i;

	// insert code 'for loop' here for array sorted in descending (reverse) order
	for(i=0;i<SIZE;i++){
		//myarray[i]=SIZE-i;
		myarray[i]=(rand()%100)+1;
	}

	// or code 'for loop' for an array of random elements here


	printf("\nArray is: ");        // print the array elements
	for(i = 0; i < SIZE; i++)
		printf("%2d ", myarray[i]);

		
	// Call the Selection Sort algorithm (pass variables myarray, and n)
    selectionSort(myarray, SIZE);

	// print out the sorted array
	printf("\n\nSorted Array is ");
	for(i = 0; i < SIZE; i++){
		printf("%2d ", myarray[i]);
	}
	
	printf("\n\nPress ENTER to continue...");
	getchar();
	return 0;
}


void selectionSort(int numbers[], int array_size)
{
	int i, j;
	int minIndex, temp;

	for (i = 0; i < array_size - 1; i++)
	{
		minIndex = i;                           // assume smallest element is here
		for (j = i + 1; j < array_size; j++)    // find the smallest element
		{
			if (numbers[j] < numbers[minIndex]){
			  minIndex=j;			  // record its index (location)
			}
		}
		temp=numbers[minIndex];			// swap element at location i
        numbers[minIndex]=numbers[i];
		numbers[i]=temp;				// with element at minIndex

	}
}
