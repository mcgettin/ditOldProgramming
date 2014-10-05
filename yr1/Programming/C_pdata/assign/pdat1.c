#include <stdio.h>
#include <stdlib.h>

struct customer{
	int id;
	char fname[40];
	char lname[40];
	int age;
	char sex;
	char addr[100];
};

struct sale{
	int id;
	char descr[100];
	float price;
	int units;
};

struct index{
	int key;
	long pos;
};

long getFsize(FILE *);  //function to return current/new size of file, comes in handy for adding records

void genCustBin(long,FILE*,FILE*);  //generate customer binary file
void genSaleBin(long,FILE*,FILE*);  // sales binary

void printCurCust(FILE*);  //prints the record currently pointed to by file pointer in the customers binary file
void printCurSale(FILE*); //as above but for sales binary, comes in useful inside other functions

void sortCust(long,FILE*); //directly sort customer binary file
void sortSale(long,FILE*); //same for sales

void findCustID(long,FILE*); //function asks user for ID input and then checks each record in file for a match
void findSaleID(long,FILE*); //as above

long addCust(long,FILE*); //asks user to input a record, then pushes the record onto the end of the binary file
long addSale(long,FILE*); //as above but for sales

struct index *genIndexCust(long,struct index*,FILE*); //generate index for costomer binary file
struct index *genIndexSale(long,struct index*,FILE*); //same for sale

struct index *sortIndex(struct index*,int no); //function that can sort either costomer index or sales index

void findIndexC(struct index*,FILE*);  //same as findCustID but uses index instead
void findIndexS(struct index*,FILE*); //as above

struct index *addIndexC(long*,struct index*,FILE*); //same as addCust but updates index too. index is realloc-ed before function call
struct index *addIndexS(long*,struct index*,FILE*); //as abouve

int main(){

	FILE *cust, *sale;  //points to .txt files
	FILE *bcust, *bsale; //points to binary files
	struct index *indexC, *indexS; //pointers for indexes 
	long endCust, endSale, endbCust, endbSale; //total length of each file 
	long rexC, rexS;  //current number of records in binary files, needed for malloc and realloc
	int opt=-1; //menu choice
	
	cust=fopen("customers.txt","r");
	sale=fopen("sales.txt","r");
	
	while(opt==-1){
		printf("(1) Generate customers & sales binary files\n");
		printf("\n(0) Exit the program \n");
		
		printf("\ninput: ");
		scanf("%d",&opt);
		getchar();

		switch(opt){
			case 0:
				fclose(cust);
				fclose(sale);
				printf("\nQuitting...\n[Press ENTER to close]");
				getchar();
				return 0;
			case 1:
				bcust=fopen("customers.bin","w+b");
				bsale=fopen("sales.bin","w+b");
				
				endCust = getFsize(cust);
				endSale = getFsize(sale);
				
				genCustBin(endCust,cust,bcust);
				genSaleBin(endSale,sale,bsale);
				
				endbCust = getFsize(bcust);
				endbSale = getFsize(bsale);
				
				printf("\n[2 Binary files have been generated]\n[Press enter]");
				getchar();
				break;
			default:
				opt=-1;
				printf("\n--Please enter a valid input--\n\n");
		}
	}
	
	opt=-1;
	while(opt==-1){
		printf("\nHow would you like to manipulate the new binary files?:\n");
		printf("(1) Using Indexes [Fast]\n(2) Directly, no indexing [Slow]\n");
		printf("\n(0) Exit the program\n");
		
		printf("\ninput: ");
		scanf("%d",&opt);
		getchar();
		
		switch(opt){
			case 0:
				fclose(cust);
				fclose(sale);
				fclose(bcust);
				fclose(bsale);
				printf("\nQuitting...\n[Press ENTER to close]");
				getchar();
				return 0;
			case 1:
				rexC=endbCust/sizeof(struct customer); //calculating number of records
				indexC=(struct index *)malloc(rexC*sizeof(struct index)); //allocating space
				indexC=genIndexCust(endbCust,indexC,bcust);  //filling space
				
				rexS=endbSale/sizeof(struct sale);
				indexS=(struct index *)malloc(rexS*sizeof(struct index));
				indexS=genIndexSale(endbSale,indexS,bsale);
				
				printf("\n[2 Indexes have been generated in memory]\n[Press enter]");
				getchar();
				break;
			case 2:
				break;
			default:
				opt=-1;
				printf("\n--Please enter a valid input--\n");
		}
	}
	
	if(opt==1){
		opt=-1;
		while(opt==-1){
			printf("\nManipulating via Indexes:\n");
			printf("(1) Add a customer\n(2) Add a sale\n");
			printf("\n(3) Find a customer\n(4) Find customer's sales\n");
			printf("\n(5) Sort customer index\n(6) Sort sales index\n");
			printf("\n(0) Exit program\n");
			
			printf("\ninput: ");
			scanf("%d",&opt);
			getchar();
			switch(opt){
				case 0:
					fclose(cust);
					fclose(sale);
					fclose(bcust);
					fclose(bsale);
					free(indexC);
					free(indexS);
					printf("Done");					
					
					printf("\nQuitting...\n[Press ENTER to close]");
					getchar();
					return 0;
				case 1:
					opt=-1;
					rexC=(endbCust/sizeof(struct customer))+sizeof(struct customer); //records+1 for realloc
					indexC=(struct index *)realloc(indexC,rexC*sizeof(struct index)); //making extra space
					indexC=addIndexC(&endbCust,indexC,bcust); //filling that space
					break;
				case 2:
					opt=-1;
					rexS=(endbSale/sizeof(struct sale))+sizeof(struct sale);
					indexS=(struct index *)realloc(indexS,rexS*sizeof(struct index));
					indexS=addIndexS(&endbSale,indexS,bsale);
					break;
				case 3:	
					opt=-1;
					findIndexC(indexC,bcust);
					break;
				case 4:	
					opt=-1;
					findIndexS(indexS,bsale);
					break;	
				case 5:
					opt=-1;
					indexC=sortIndex(indexC,rexC);
					printf("\n[Customers Index sorted]\n[Press enter]");
					getchar();
					break;
				case 6:
					opt=-1;
					indexS=sortIndex(indexS,rexS);
					printf("\n[Sales Index sorted]\n[Press enter]");
					getchar();
					break;
				default:
					opt=-1;
					printf("\n--Please enter a valid input--\n");
			}
		}
	}
	
	if(opt==2){
		opt=-1;
		while(opt==-1){
			printf("\nManipulating binary files directly:\n");
			printf("(1) Add a customer\n(2) Add a sale\n");
			printf("\n(3) Find a customer\n(4) Find customer's sales\n");
			printf("\n(5) Sort customer file [Warning: Slow! (5-10mins)]\n(6) Sort sales file[Warning: Very Slow!! (~30mins)]\n");
			printf("\n(0) Exit program\n");
			
			printf("\ninput: ");
			scanf("%d",&opt);
			getchar();
			switch(opt){
				case 0:
					fclose(cust);
					fclose(sale);
					fclose(bcust);
					fclose(bsale);

					printf("\nQuitting...\n[Press ENTER to close]");
					getchar();
					return 0;
				case 1:
					opt=-1;
					endbCust=addCust(endbCust,bcust); //adds customer and updates length of file
					break;
				case 2:
					opt=-1;
					endbSale=addSale(endbSale,bsale);
					break;
				case 3:	
					opt=-1;
					findCustID(endbCust,bcust);
					break;
				case 4:	
					opt=-1;
					findSaleID(endbSale,bsale);
					break;	
				case 5:
					opt=-1;
					sortCust(endbCust,bcust);
					printf("\n[Customers file sorted]\n[Press enter]");
					getchar();
					break;
				case 6:
					opt=-1;
					sortSale(endbSale,bsale);
					printf("\n[Sales file sorted]\n[Press enter]");
					getchar();
					break;
				default:
					opt=-1;
					printf("\n--Please enter a valid input--\n");
			}
		}
	}
	
	return 0; //should logically never be executed, but just in case...
}


long getFsize(FILE* fp){
	fseek(fp,0L,SEEK_END);
	return ftell(fp);
}


void genCustBin(long end,FILE* fpin, FILE* fpout){
	rewind(fpin);
	
	struct customer str;
	char buff[10];
	
	while(ftell(fpin)<end){
		fgets(buff,sizeof(buff),fpin);
		str.id=atoi(buff);

		fgets(str.fname,40,fpin);
		
		fgets(str.lname,40,fpin); 
		
		fgets(buff,sizeof(buff),fpin);
		str.age=atoi(buff);
		
		fgets(buff,sizeof(buff),fpin);
		str.sex=buff[0];
		
		fgets(str.addr,100,fpin); 
		
		fwrite(&str,sizeof(struct customer),1,fpout); 
	}
	
}

void genSaleBin(long end,FILE* fpin, FILE* fpout){
	rewind(fpin);
	
	struct sale str;
	char buff[10];
	while(ftell(fpin)<end){
		fgets(buff,sizeof(buff),fpin);
		str.id=atoi(buff);
		
		fgets(str.descr,100,fpin); 
		
		fgets(buff,sizeof(buff),fpin);
		str.price=atof(buff);
	
		fgets(buff,sizeof(buff),fpin);
		str.units=atoi(buff);
		
		fwrite(&str,sizeof(struct sale),1,fpout); 
	}	
}


void printCurCust(FILE* fpin){
	
	struct customer cus;
	
	fread(&cus,sizeof(struct customer),1,fpin);
	
	printf("\n----Customer----\n");
	printf("ID:         %d\n",cus.id);
	printf("First Name: %s",cus.fname);
	printf("Last Name:  %s",cus.lname);
	printf("Age:        %d\n",cus.age);
	printf("Gender:     %c\n",cus.sex);
	printf("Address:    %s\n",cus.addr);
}

void printCurSale(FILE* fpin){
	
	struct sale sal;
	
	fread(&sal,sizeof(struct sale),1,fpin);
	
	printf("\n----Sale----\n");
	printf("ID:    %d\n",sal.id);
	printf("Item:  %s",sal.descr);
	printf("Price: %.2f\n",sal.price);
	printf("Units: %d\n",sal.units);
}


void sortCust(long end,FILE* fpio){
	rewind(fpio);
	
	struct customer curr,next;
	int done=0;
	int pass=0;
	while(!done){
		done=1;
		rewind(fpio);
		pass++;
		while(ftell(fpio)<(end-(sizeof(struct customer)*pass))){
			//printf("\rprogress: %.3f%%", pass/end);
			//printf("ftell: %ld\n",ftell(fpio));
			fread(&curr,sizeof(struct customer),1,fpio);
			fread(&next,sizeof(struct customer),1,fpio);
			
			if(curr.id>next.id){
				//printf("\nSwitch!\n");
				done=0;
				fseek(fpio,-(sizeof(struct customer)*2),SEEK_CUR);
				fwrite(&next,sizeof(struct customer),1,fpio);
				fwrite(&curr,sizeof(struct customer),1,fpio);
				fseek(fpio,-sizeof(struct customer),SEEK_CUR);
			}else{
				fseek(fpio,-sizeof(struct customer),SEEK_CUR);
			}
		}
		//printf("\nCustomer Sort Pass: %d\n",pass);
	}
}

void sortSale(long end,FILE* fpio){
	rewind(fpio);

	struct sale curr,next;
	int done=0;
	int pass=0;
	while(!done){
		done=1;
		rewind(fpio);
		pass++;
		while(ftell(fpio)<(end-(sizeof(struct sale)*pass))){
			//printf("ftell: %ld\n",ftell(fpio));
			fread(&curr,sizeof(struct sale),1,fpio);
			fread(&next,sizeof(struct sale),1,fpio);
			
			if(curr.id>next.id){
				//printf("\nSwitch!\n");
				done=0;
				fseek(fpio,-(sizeof(struct sale)*2),SEEK_CUR);
				fwrite(&next,sizeof(struct sale),1,fpio);
				fwrite(&curr,sizeof(struct sale),1,fpio);
				fseek(fpio,-sizeof(struct sale),SEEK_CUR);
			}else{
				fseek(fpio,-sizeof(struct sale),SEEK_CUR);
			}
		}
		//printf("\nSale Sort Pass: %d\n\n",pass);
	}
}


void findCustID(long end,FILE* fpin){
	rewind(fpin);
	
	struct customer cus;
	int id;
	printf("\nCheck for Customer id: ");
	scanf("%d",&id);
	getchar();
	
	while(ftell(fpin)<end){
		fread(&cus,sizeof(struct customer),1,fpin);
		if(cus.id==id){
			printf("\n--Customer %d found:--\n",id);
			printf("ID:         %d\n",cus.id);
			printf("First Name: %s",cus.fname);
			printf("Last Name:  %s",cus.lname);
			printf("Age:        %d\n",cus.age);
			printf("Gender:     %c\n",cus.sex);
			printf("Address:    %s\n",cus.addr);
			return;
		}
	}
	printf("\n--Customer ID Not Found--\n");
}

void findSaleID(long end,FILE* fpin){
	rewind(fpin);
	
	struct sale sal;
	int find=0,id;
	
	printf("\nCheck for Customer id: ");
	scanf("%d",&id);
	getchar();
	
	while(ftell(fpin)<end){
		fread(&sal,sizeof(struct sale),1,fpin);
		if(sal.id==id){
			if(!find){
				printf("\nCustomer %d bought: \n",id);
			}
			printf("\nItem:  %s",sal.descr);
			printf("Price: %.2f\n",sal.price);
			printf("Units: %d\n",sal.units);
			find=1;
		}
	}
	if(!find){
		printf("\n--Sale ID Not Found--\n");
	}	
}


long addCust(long end,FILE* fpio){
	rewind(fpio);

	struct customer new,cus;
	
	printf("\nPlease input Info for new Customer:\n");
	printf("ID: ");
	scanf("%d",&new.id);
	getchar();
	
	printf("First Name: ");
	fgets(new.fname,40,stdin);
	
	printf("Last Name: ");
	fgets(new.lname,40,stdin);
	
	printf("Age: ");
	scanf("%d",&new.age);
	getchar();
	
	printf("Sex: ");
	new.sex=fgetc(stdin);
	getchar();
	
	printf("Address: ");
	fgets(new.addr,100,stdin);
	
	while(ftell(fpio)<end){
		fread(&cus,sizeof(struct customer),1,fpio);
		if(new.id==cus.id){
			printf("\n--Customer already exists--\n");
			return end;
		}
	}
	fseek(fpio,0L,SEEK_END);
	fwrite(&new,sizeof(struct customer),1,fpio);
	
	return getFsize(fpio);
}

long addSale(long end,FILE* fpio){
	rewind(fpio);
	
	struct sale new,sal;
	
	printf("\nPlease input Info for new Sale:\n");
	printf("Customer ID: ");
	scanf("%d",&new.id);
	getchar();
	
	printf("Item Description: ");
	fgets(new.descr,100,stdin);
	
	printf("Price: ");
	scanf("%f",&new.price);
	getchar();
	
	printf("Units: ");
	scanf("%d",&new.units);
	getchar();
		
	while(ftell(fpio)<end){
		fread(&sal,sizeof(struct sale),1,fpio);
		if(new.id==sal.id){
			fseek(fpio,0L,SEEK_END);
			fwrite(&new,sizeof(struct sale),1,fpio);
			
			return getFsize(fpio);
		}
	}
	printf("\n-Error: Customer Record not found-\n");
	return end;
}


struct index *genIndexCust(long end,struct index *ind, FILE* fpin){
	rewind(fpin);
	
	int i=0;
	struct customer cus;
	
	while(ftell(fpin)<end){
		fread(&cus,sizeof(struct customer),1,fpin);
		
		ind[i].key=cus.id;
		ind[i].pos=ftell(fpin)-sizeof(struct customer);
		i++;
	}
	return ind;	
}

struct index *genIndexSale(long end,struct index *ind, FILE* fpin){
	rewind(fpin);
	
	int i=0;
	struct customer sal;
	
	while(ftell(fpin)<end){
		fread(&sal,sizeof(struct sale),1,fpin);
		
		ind[i].key=sal.id;
		ind[i].pos=ftell(fpin)-sizeof(struct sale);
		i++;
	}
	return ind;
}


struct index *sortIndex(struct index* ind,int no){
	
	int i,postemp,done=0;
	long keytemp;
	
	while(!done){
		done=1;
		for(i=0; i<(no-1); i++){	
			if(ind[i].key > ind[i+1].key){
				done=0;
				
				keytemp=ind[i].key;
				postemp=ind[i].pos;
				
				ind[i].key=ind[i+1].key;
				ind[i].pos=ind[i+1].pos;
				
				ind[i+1].key=keytemp;
				ind[i+1].pos=postemp;
			}
		}
	}
	return ind;
}


void findIndexC(struct index* ind,FILE* fpin){
	int i,id;
	
	printf("\nCheck for Customer id: ");
	scanf("%d",&id);
	getchar();
	
	for(i=0; ind[i].key!=0; i++){	
		if(id==ind[i].key){
			fseek(fpin,ind[i].pos,SEEK_SET);
			printf("\nFound ID %d at position %d\n",id,ind[i].pos);
			printCurCust(fpin);
			return;
		}
	}
	printf("\n--Index Key not found--\n");
}

void findIndexS(struct index* ind,FILE* fpin){
	int i,find=0,id;
	
	printf("\nCheck for Customer id: ");
	scanf("%d",&id);
	getchar();
	
	for(i=0; ind[i].key!=0; i++){	
		if(id==ind[i].key){
			fseek(fpin,ind[i].pos,SEEK_SET);
			printf("\nFound ID %d at position %d\n",id,ind[i].pos);
			printCurSale(fpin);
			find=1;
		}
	}
	if(!find){
		printf("\n--Index Key not found--\n");
	}	
}


struct index *addIndexC(long *pend,struct index* ind,FILE* fpio){
	int i=0;
	struct customer new;
	
	printf("\nPlease input Info for new Customer:\n");
	printf("ID: ");
	scanf("%d",&new.id);
	getchar();
	
	printf("First Name: ");
	fgets(new.fname,40,stdin);
	
	printf("Last Name: ");
	fgets(new.lname,40,stdin);
	
	printf("Age: ");
	scanf("%d",&new.age);
	getchar();
	
	printf("Sex: ");
	new.sex=fgetc(stdin);
	getchar();
	
	printf("Address: ");
	fgets(new.addr,100,stdin);
	
	while(ind[i].key!=0){	
		if(new.id==ind[i].key){
			printf("\n--customer already exists--\n");
			return 0;
		}
		i++;
	}
	fseek(fpio,0L,SEEK_END);
	ind[i].key=new.id;
	ind[i].pos=ftell(fpio);
	fwrite(&new,sizeof(struct customer),1,fpio);
	
	*pend=getFsize(fpio);
	
	return ind;
	
}

struct index *addIndexS(long *pend,struct index* ind,FILE* fpio){
	int i=0,find=0;
	
	struct sale new;
	
	printf("\nPlease input Info for new Sale:\n");
	printf("Customer ID: ");
	scanf("%d",&new.id);
	getchar();
	
	printf("Item Description: ");
	fgets(new.descr,100,stdin);
	
	printf("Price: ");
	scanf("%f",&new.price);
	getchar();
	
	printf("Units: ");
	scanf("%d",&new.units);
	getchar();
	
	while(ind[i].key!=0){	
		if(new.id==ind[i].key){
			find=1;
		}
		i++;
	}
	if(!find){
		printf("\n--Customer ID not found--\n");
		return ind;
	}
	fseek(fpio,0L,SEEK_END);
	ind[i].key=new.id;
	ind[i].pos=ftell(fpio);
	fwrite(&new,sizeof(struct sale),1,fpio);
	
	*pend=getFsize(fpio);
	
	return ind;

}

