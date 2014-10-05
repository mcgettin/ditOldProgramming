#include <stdio.h>

struct record{
	char title[64];
	char author[64];
	float price;
	short year;
};
typedef struct record t_book;
int main(){

	t_book book;
	FILE *fp;
	fp=fopen("database.dat","wb");
	int opt=0;
	
	printf("|| Books to File Program ||\n");
	while(opt!=2){
		printf("\n(1) Insert a new book\n(2) Quit\n");
		scanf("%d",&opt);
		getchar();
		if(opt==2){
			puts("\nQuitting...");
		}else if(opt==1){
			printf("\nPlease insert:\n");
			printf("\nTitle: ");
			gets(book.title);
			//fgets(book.title,64,stdin);
			printf("\nAuthor: ");
			gets(book.author);
			//fgets(book.title,64,stdin);
			printf("\nYear: ");
			scanf("%d",&book.year);
			printf("\nPrice: ");
			scanf("%f",&book.price);
			fwrite(&book,sizeof(t_book),1,fp);
		}else{
			printf("\nInvalid input. Try again...\n\n");
		}
	}
	
	printf("\nDone.\n[Hit Enter to close]");
	getchar();
	fclose(fp);
	return 0;
}
