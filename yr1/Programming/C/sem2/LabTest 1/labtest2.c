//Lab test 2: using functions and arrays
//Student: Neil McGettigan
//Number: C12810959

#include <stdio.h>
#define SIZE 3	

void toFahr(float[]);  //fahrenheit function
void toKel(float[]);  //kelvin function

int main(){
	
	int i;
	float temps[SIZE]; //size of 3
	
	//Taking in array values from the user
	printf("Input 3 temperature values in celcius:\n");
	for(i=0;i<SIZE; i++){
		scanf("%f",&temps[i]);
	}
	
	toFahr(temps); //calling function to calculate fahrenheit
	puts("\n"); //formatting
	
	toKel(temps); //calling function to calculate kelvin
	puts("\n");
	
	//code to help the user exit gracefully
	printf("\n[Press any key to close]");
	getchar();
	getchar();
	return 0;
}

void toFahr(float arr[]){
	
	int i;
	float fah[SIZE]; //to store fahrenheit copies of temps elements
	
	for(i=0;i<SIZE;i++){ //calculates fahrenheit values and stores
		fah[i]=((arr[i]/5)*9)+32;
	}
	
	for(i=0;i<SIZE;i++){ //displays the celcius and fahrenheit together
		printf("\n%.2f'C is %.2f'F (Fahrenheit)\n",arr[i],fah[i]);
	}
}

void toKel(float arr[]){
	
	int i;
	float kel[SIZE]; //to store kelvin copies of temps elements
	
	for(i=0;i<SIZE;i++){ //calculating
		kel[i]=arr[i]+273;
	}
	for(i=0;i<SIZE;i++){ //displaying
		printf("\n%.2f'C is %.2f'K (Kelvin)\n",arr[i],kel[i]);
	}
}

