#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  FILE *filer;
  FILE *filew;
  char ch;
  clock_t begin, end;
  double time_spent;

  begin = clock();

  filer = fopen("big_text.txt","r");
  if (filer ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }

  filew = fopen("big_text_copy.txt","w");
  if (filew ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  int i;
  //copy char by char 
  while((ch = fgetc( filer )) != EOF) {  
    
	fputc(ch,filew);
		
  }
  fclose(filer);
  fclose(filew);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f",time_spent);

  return 0;
}
