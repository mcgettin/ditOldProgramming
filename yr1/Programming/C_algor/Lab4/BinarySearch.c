#include <stdio.h>

int BinarySearch(int array[], int min_index, int max_index, int key);

int main()                             // main program to test the algorithm
{
	//declare and initialise a simple array of size 10
   
	int myarray[100] = {2, 4, 7, 8, 11, 14, 17, 19, 21, 24 };
	int position, key,i;
	int low, high;

	for(i=0; i<100;i++){
		myarray[i]=2*i+1;
	}
	
	printf("\nArray is ");
	for(i = 0; i < 100; ++i)
		printf("%d ", myarray[i]);

	printf("\nInput value to search for: ");
	scanf("%d", &key);
	low = 0;               // Initial min index
	high = 99;              // Initial max index

	// Call the Binary Search algorithm

	position = BinarySearch(myarray, low, high, key);

	if( position == -1)
		printf("\nValue %d not found\n\n", key);      // key not found
	else
		printf("\nValue %d found at array position: %d\n\n", myarray[position],position);

	getchar();
	getchar();
	return 0;
}



int BinarySearch(int array[], int min_index, int max_index, int key)
{
	int position = -1;                  // indicates key not found (default)
	int mid;

	while (min_index <= max_index)
	{

		mid = (min_index + max_index)/2; // find the middle index in the array.
		printf("array[%d]= %d\n",mid,array[mid]);
		if( key == array[mid])             // COMPARE KEY with A[k] here
		{
			position = mid;
			return position;	            // return position of key in array[]
		}
		else if (key < array[mid])             // search first half
			max_index=mid-1;                 // COMPUTE max_index HERE, first half
		else                                   // search second half
			min_index=mid+1;                 // COMPUTE min_index HERE, second half
	}
	return position;                    // indicates key is not found
}                                      // after 'while' loop is finished



