#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char student[20];
  int mark;
  
  fp = fopen("marks.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  while (fscanf(fp, "%s" "%i", student , &mark) != EOF) {
	if (mark >= 40) {
		printf("%s passed the exam ! \n", student);
	}
  }  
  fclose(fp);
	
  printf("\n[press ENTER to close]");
  getchar();	
  return 0;
}


