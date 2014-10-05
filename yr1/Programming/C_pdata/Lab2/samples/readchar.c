#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char ch;
  ch='a';
// 'a' - 'z' 97-122 'A' - 'Z' 65-90
  //printf("%i", ch);
  fp = fopen("myfile.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  while((ch = fgetc( fp )) != EOF) {
    printf("%c", ch);
  }
  fclose(fp);
  return 0;
}
