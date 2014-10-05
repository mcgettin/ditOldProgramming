#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  FILE *fpass;
  FILE *ffail;
  
  char student[20];
  int mark;
  int total=0;
  int num=0;
  
  fp = fopen("marks.txt","r");
  fpass = fopen("pass.txt","w");
  ffail = fopen("fail.txt","w");
  
  if (fp ==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
	while (fscanf(fp, "%s" "%d", student , &mark) != EOF) {
		if (mark >= 40) 
			{printf("%s passed the exam ! \n", student);
			 fprintf(fpass,"%s passed the exam ! \n", student);}
		  
		else
		{
			printf("%s failed the exam ! \n", student);
			fprintf(ffail,"%s failed the exam ! \n", student);
		}
		//compute the average
		total = total + mark;
		num++;
		}
	printf("The total is: %d \n",total);	
	printf("The number of students is: %d \n",num);
	printf("The average mark is: %.2f",(double)(total/num));
	fclose(fp);
	fclose(fpass);
	fclose(ffail);
  return 0;}


