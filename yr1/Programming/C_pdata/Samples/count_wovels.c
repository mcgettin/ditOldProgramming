#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char ch;
  int co =0;
  int wo =0;
  int tot = 0;

  // 'a' - 'z' 97-122 'A' - 'Z' 65-90
  fp = fopen("italian.txt","r");
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  while((ch = fgetc( fp )) != EOF) {
    if (ch>='a' && ch<='z' )  //check if the char is a letter
		{ tot++;  //update the number of characters
			if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
			{ wo++;} else {co++;}
		}
  }
  printf ("Totals: %d \n", tot);
  printf ("Vovels: %d \n", wo);
  printf ("Consonants: %d \n", co);
  printf ("Percentage of Vovels: %.3f percent", (double) wo/tot);
  fclose(fp);
  getchar();
  return 0;
}
