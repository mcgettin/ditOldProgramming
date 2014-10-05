#include <stdio.h>
#define SIZE 15

int main(){

	char city[SIZE], country[SIZE];
	char cityT[SIZE];
	long pop,tot=0,topP=0;
	FILE *fp, *fIre, *fMil;
	fMil=fopen("fMil.txt","wt");
	fIre=fopen("fIre.txt","wt");
	fp=fopen("population.txt","rt");
	
	while(fscanf(fp,"%s %s %ld", country,city,&pop)!=EOF){
		if(strcmp(country,"ireland")==0){
			//printf("\ncountry: %s\n City: %s\n",country,city);
			fputs(city,fIre);
			fputc('\n',fIre);
		}
		if(pop>=1000000){
			//printf("\npopulation: %ld\n",pop);
			fputs(city,fMil);
			fputc(' ',fMil);
			fprintf(fMil,"%ld",pop);
			fputc('\n',fMil);
		}
		if(pop>topP){
		topP=pop;
		strcpy(cityT,city);
		}
		tot+=pop;
	}
	printf("Total Population: %ld\n",tot);
	printf("Highest population: %s %ld\n",cityT,topP);
	
	printf("\n[Press any key to clsose]");
	getchar();
	fclose(fMil);
	fclose(fIre);
	fclose(fp);
	return 0;
}
