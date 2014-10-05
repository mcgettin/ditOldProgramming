#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50

// Bubble sort algorithm
void bubbleSort(int numbers[], int array_size);


int main()   // main program to test the algorithm
{
	//srand(time(NULL));

	//int myarray[15] = {3, 4, 7, 8, 31, 22, 17, 6, 5, 1, 13, 21, 33, 9, 5 };
	int myarray[SIZE];
	int i, n;
	n = SIZE;                             // size of array

	for(i=0;i<SIZE;i++){
		myarray[i]=(rand()%(SIZE*2))+1;
	}
	printf("\nArray is:        ");
	for(i=0; i<SIZE;i++){
		printf("%d ",myarray[i]);
	}


	// Call the Bubble sort algorithm (pass variables myarray, and n)
	bubbleSort(myarray, n);

	// print out the sorted array
	printf("\n\nSorted Array is: \n");
	for(i=0; i<SIZE;i++){
		printf("%d ",myarray[i]);
	}
	
	
	printf("\n\n[Press Enter to close]");
	getchar();

	return 0;
}


void bubbleSort(int numbers[], int array_size)
{
	int i, j, temp;
	puts("\n");
	
	for (i = (array_size - 1); i >0; i--)     // pass number (last index of array to sort)
	{	
		
		puts("\n");
		for(j=0; j<SIZE;j++){
		printf("%d ",numbers[j]);
		}
		
		printf("\n Pass %2d ", array_size - i);
		for (j = 0; j <= i; j++)
		{
			if (numbers[j]>numbers[j+1])    // ie,  (j-1)st number > j-th number
			{
				temp=numbers[j+1];
				numbers[j+1]=numbers[j];
				numbers[j]=temp;
			}
		}
	}
}

