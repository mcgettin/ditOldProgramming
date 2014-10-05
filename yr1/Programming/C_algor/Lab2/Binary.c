#include <stdio.h>
#include <stdlib.h>

#define MAXBITS  32

main()
{
	int bits[MAXBITS];       // declare array bits, to hold the bits.
	int index,i;
	int number, num;

	//number = 12;              // choose a number to test the code
	

	for(num=100; num<=128; num++){
		index = 0;
		number=num;
		printf("Binary of Decimal %3d = ", number);
		while (number>0){
			bits[index]=number%2;
			number=number/2;
			index++;
		}
		
		// Print out the bits in reverse order, from last to first.
		for (i = index - 1; i >= 0; i--)
		{
		printf(" %1d", bits[i]);
		}
		printf("\n");
	}
   getchar();
}

