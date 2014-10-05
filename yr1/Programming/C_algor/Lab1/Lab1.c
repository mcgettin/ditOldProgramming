#include <stdio.h>
#include <stdlib.h>
#define N 20

// function prototypes

int max_element(int A[], int n);
int min_element(int A[], int n);
float mean_element(int A[], int n); 

main()
{
    int A[N];         //declare array A, of size N to store the numbers
    int i;
    int small, large;
    float mean;

    // setup an array A of elements, all integers.
    
    for (i = 0; i < N; i++)
    {
    	 A[i] = i+1;
		// printf("%d\n",A[i]); //debug
    }
    // Compute the smallest, largest and the average element

    small = min_element(A, N);
    large = max_element(A, N);
    mean = mean_element(A, N);

    printf("\n\n  Output of Results ");
    printf("\n_____________________________________");
    printf("\n  Min  element is %5d          ",  small);
    printf("\n  Max  element is %5d          ",  large);
    printf("\n  Mean element is %5.2f        ",  mean);
    printf("\n_____________________________________");

    getchar();
}

int min_element(int A[], int n)
{
	int i, smallest=A[0];
	for(i=1;i<n;i++){
		if(A[i]<smallest){
			smallest=A[i];
		}
	}
	return smallest;
}

int max_element(int A[], int n)
{
	int i, biggest=A[0];
	for(i=1;i<n;i++){
		if(A[i]>biggest){
			biggest=A[i];
		}
	}
	return biggest;
}

float mean_element(int A[], int n)
{
	int i, sum=0;
	float mean;
 	for(i=0;i<n;i++){
		sum+=A[i];
	}
	//printf("\nelms: %d\nsum: %d\n",elms,sum); //debug
	mean=(float)sum/n;
	
	return mean;
}
