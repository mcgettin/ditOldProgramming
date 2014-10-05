#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  int LINE_MAX = 50; //maximum size of a string
  char line[LINE_MAX];
  fp = fopen("myfile.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  while(fgets( line, LINE_MAX, fp ) != NULL) {
    printf("%s", line);
  }
  fclose(fp);
  getchar();
  return 0;}
