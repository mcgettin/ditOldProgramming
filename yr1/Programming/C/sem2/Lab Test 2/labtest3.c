/*
Student Name: Neil McGettigan
Student Number: C12810959
Program: Lab Test 3s
Date: 18/04/2013
*/

#include <stdio.h> 

/*Structure for meteorological info*/
struct meteo{
	char city[30];
	float temp;
	int rain;
	float sun;
};

int main(){
	
	printf("---LabTest3: Weather Program---\n\n");
	
	struct meteo weather[4];
	float avrTemp=0;
	int i,hiRain,loRain;
	
	/*Inputting given info for all cities*/	
	strcpy(weather[0].city,"Dublin");
	weather[0].temp=14.2;
	weather[0].rain=20;
	weather[0].sun=167.4;
	
	strcpy(weather[1].city,"Toronto");
	weather[1].temp=20.6;
	weather[1].rain=12;
	weather[1].sun=226.3;

	strcpy(weather[2].city,"San Francisco");
	weather[2].temp=25.1;
	weather[2].rain=8;
	weather[2].sun=303.8;
	
	strcpy(weather[3].city,"Tokyo");
	weather[3].temp=21.7;
	weather[3].rain=10;
	weather[3].sun=251.1;
	
	/*(a)*/
	printf("(a)\n");
	
	for(i=0;i<4;i++){
		printf("Average sunshine per day in %s is: %.2f hours\n",weather[i].city,(weather[i].sun/31));
	}
	
	/*(b)*/
	printf("\n(b)\n");
	
	for(i=0;i<4;i++){
		avrTemp+=weather[i].temp; //add each cities' temp to avrTemp
	}
	printf("Average temperature for all cities is: %.2f'C\n",avrTemp);
	
	/*(c)*/
	printf("\n(c)\n");
	
	hiRain=weather[0].rain; //init hiRain and lowRain before loop
	loRain=hiRain;
	for(i=1;i<4;i++){
		if(weather[i].rain>hiRain){
			hiRain=weather[i].rain;
		}
		if(weather[i].rain<loRain){
			loRain=weather[i].rain;
		}
	}
	printf("Highest Rainfall: %dmm\nLowest Rainfall: %dmm\nDifference: %dmm\n",hiRain,loRain,(hiRain-loRain));
	
	printf("\n\n[Press ENTER to close]");
	getchar();
	return 0;
}
