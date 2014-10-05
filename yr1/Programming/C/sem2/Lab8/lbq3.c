#include <stdio.h>

struct DOB{
	int day;
	int month;
	int year;
};

struct height{
	int feet;
	int inches;
};

struct weight{
	int pounds;
	int ounces;
};

struct bio{
	char fName[11];
	char lName[21];
	struct DOB born;
	struct height tall;
	struct weight size;
	char eyes[9];
	char nation[26];
};

int main(){
	
	struct bio pleb,lad;
	printf("Input Info:\n");
	printf("First Name: ");
	gets(pleb.fName);
	printf("Last Name: ");
	gets(pleb.lName);
	printf("Date of Birth--\n");
	printf("Day: ");
	scanf("%d",&pleb.born.day);
	printf("Month: ");
	scanf("%d",&pleb.born.month);
	printf("Year: ");
	scanf("%d",&pleb.born.year);
	printf("Height--\n");
	printf("Feet: ");
	scanf("%d",&pleb.tall.feet);
	printf("Inches: ");
	scanf("%d",&pleb.tall.inches);
	printf("Weight--\n");
	printf("Pounds: ");
	scanf("%d",&pleb.size.pounds);
	printf("Ounces: ");
	scanf("%d",&pleb.size.ounces);
	printf("Eye Colour: ");
	getchar();
	gets(pleb.eyes);
	printf("Nationality: ");
	gets(pleb.nation);
	
	printf("\nBio for Pleb is:\n");
	printf("First Name: ");
	puts(pleb.fName);
	printf("Last Name: ");
	puts(pleb.lName);
	printf("Date of Birth--\n");
	printf("Day: ");
	printf("%d\n",pleb.born.day);
	printf("Month: ");
	printf("%d\n",pleb.born.month);
	printf("Year: ");
	printf("%d\n",pleb.born.year);
	printf("Height--\n");
	printf("Feet: ");
	printf("%d\n",pleb.tall.feet);
	printf("Inches: ");
	printf("%d\n",pleb.tall.inches);
	printf("Weight--\n");
	printf("Pounds: ");
	printf("%d\n",pleb.size.pounds);
	printf("Ounces: ");
	printf("%d\n",pleb.size.ounces);
	printf("Eye Colour: ");
	puts(pleb.eyes);
	printf("Nationality: ");
	puts(pleb.nation);
	
	lad=pleb;
	
	printf("\nBio for Lad is:\n");
	printf("First Name: ");
	puts(lad.fName);
	printf("Last Name: ");
	puts(lad.lName);
	printf("Date of Birth--\n");
	printf("Day: ");
	printf("%d\n",lad.born.day);
	printf("Month: ");
	printf("%d\n",lad.born.month);
	printf("Year: ");
	printf("%d\n",lad.born.year);
	printf("Height--\n");
	printf("Feet: ");
	printf("%d\n",lad.tall.feet);
	printf("Inches: ");
	printf("%d\n",lad.tall.inches);
	printf("Weight--\n");
	printf("Pounds: ");
	printf("%d\n",lad.size.pounds);
	printf("Ounces: ");
	printf("%d\n",lad.size.ounces);
	printf("Eye Colour: ");
	puts(lad.eyes);
	printf("Nationality: ");
	puts(lad.nation);
	
	
	printf("\n[Press ENTER to close]");
	getchar();
	return 0;
}
