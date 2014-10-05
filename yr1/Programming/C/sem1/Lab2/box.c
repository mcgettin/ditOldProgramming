#include <stdio.h>

int main(){
	
	float hi=10.0;
	float len=11.5;
	float wid=2.5;
	printf("Box has dimensions:-\nheight: %f\nlength: %f\nwidth: %f\n",hi,len,wid);
	
	float vol=hi*wid*len;
	printf("\nThe volume is: %f\n",vol);

	float tot_area=2*hi+2*wid+2*len;
	printf("\nThe total surface area is: %f", tot_area);
	
}
