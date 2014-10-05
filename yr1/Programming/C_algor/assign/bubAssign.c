#include <stdio.h>
#include <time.h>

// Bubble sort algorithm
void bubSort(int[], int);
void impBsort(int[],int);

int main()   // main program to test the algorithm
{
	srand(time(NULL));

	int i, myarray[4000],myarray2[4000];
	int n=4000;
	
	/*initalizing both arrays. One for ordered backwards
	  array and one which have random numbers from 1 to 2n*/
	for(i=0;i<n;i++){
		myarray[i]=n-i;
		myarray2[i]=(rand()%(n*2))+1;
	}
	
	printf("N = %d",n);
	
	// Call the Bubble sort algorithm (pass variables myarray, and n)
	bubSort(myarray, n);
	impBsort(myarray2,n);
	
	
	printf("\n\n[Press Enter to close]");
	getchar();

	return 0;
}


void bubSort(int numbers[], int array_size)
{
	int i, j, temp,pass=0; //temp used for swaps, pass counts the array passes
	long comp=0,swap=0; //comp counts the comparisons, swap counts the swaps
	
	for (i = (array_size - 1); i>0; i--) // pass number is last index of array
	{	
		pass++;
	
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
	for (i = (array_size - 1); i >0 && done!=1; i--) 
	{	
		pass++;
		done=1;
		
		for (j = 0; j < i; j++)
		{
			comp++;
			if (numbers[j]>numbers[j+1])    // ie,  (j-1)st number > j-th number
			{
				swap++;
				temp=numbers[j+1];
				numbers[j+1]=numbers[j];
				numbers[j]=temp;
				done=0;	//swap occurs, so for loop will continue
			}
		}
	}
	printf("\n\n--Improved Bubble Sort--\nPasses: %d\nComparisons: %lu\nSwaps: %lu",pass,comp,swap);
}



