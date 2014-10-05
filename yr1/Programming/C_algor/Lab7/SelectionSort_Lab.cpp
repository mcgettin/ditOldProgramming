#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void selectionSort(int numbers[], int array_size)
{
	int i, j;
	int minIndex, temp;

	for (i = 0; i < array_size - 1; i++)
	{
		minIndex = i;                           // assume smallest element is here
		for (j = i + 1; j < array_size; j++)    // find the smallest element
		{
			if (numbers[j] < numbers[minIndex])
			  // change the minIndex              // record its index (location)
		}
		// insert code here                     // swap element at location i
		// to swap elements                     // with element at minIndex

	}
}

void main()                          // main program to test the algorithm
{
	// Declare and initialise a simple array of size 100

	int myarray[100];
	int i, n;
	n = 100;                               // size of array

	// insert code 'for loop' here for array sorted in descending (reverse) order


	// or code 'for loop' for an array of random elements here


	printf("\nArray is:        ");        // print the array elements
	for(i = 0; i < 100; i++)
		printf("%2d ", myarray[i]);

	// Call the Selection Sort algorithm (pass variables myarray, and n)
   selectionSort(myarray, n);

	// print out the sorted array
	printf("\n\nSorted Array is ");
	for(i = 0; i < 100; i++)
		printf("%2d ", myarray[i]);

   printf("\n\nPress any key to continue...");
   getch();
}


