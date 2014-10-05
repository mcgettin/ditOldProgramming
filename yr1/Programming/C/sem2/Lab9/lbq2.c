#include <stdio.h>
#define MAX 30

struct flight{
	char airName[MAX];
	int flyNum;
	char pasSur[MAX];
	int seatNum;
	char dest[MAX];
	int numBags;
};

void passInfo(struct flight*);
void printPass(struct flight);

int main(){
	
	int i;
	struct flight pass[3];
	struct flight *pPass;
	
	printf("--Inputting Passenger Info--\n");
	for(i=0;i<3;i++){
		pPass=&pass[i];
		printf("\nPassenger %d:\n",i+1);
		passInfo(pPass);
	}
	
	printf("\n--Displaying Passenger Info--\n");
	for(i=0; i<3; i++){
		printf("\nPassenger %d:\n",i+1);
		printPass(pass[i]);
	}
	
	printf("\n\n[Press ENTER to close]");
	getchar();
	return 0;
}


void passInfo(struct flight *cust){
	printf("Airliner Name: ");
	fgets(cust->airName,MAX,stdin);
	printf("Flight Number: ");
	scanf("%d",&cust->flyNum);	
	getchar();
	printf("Passenger Surname: ");
	fgets(cust->pasSur,MAX,stdin);
	printf("Seat Number: ");	
	scanf("%d",&cust->seatNum);
	getchar();
	printf("Destination: ");
	fgets(cust->dest,MAX,stdin);
	printf("Number of Bags: ");	
	scanf("%d",&cust->numBags);
	getchar();
}

void printPass(struct flight cust){
	printf("Airliner Name: %s",cust.airName);
	printf("Flight Number: %d\n",cust.flyNum);
	printf("Passenger Surname: %s",cust.pasSur);
	printf("Seat Number: %d\n",cust.seatNum);	
	printf("Destination: %s",cust.dest);
	printf("Number of Bags: %d\n",cust.numBags);	
}
