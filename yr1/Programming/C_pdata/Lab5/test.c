#include <stdio.h>

struct student{
	int id;
	char f_name[16];
	char s_name[32];
	int results[5];
};
typedef struct student pleb;

int main(){
	
	pleb joe;
	joe.results[1]=88;
	
	printf("%d",joe.results[1]);

	getchar();
	return 0;
}
