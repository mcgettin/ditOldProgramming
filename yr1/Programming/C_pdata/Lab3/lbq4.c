#include <stdio.h>
#define SIZE 64

int main(){
	
	int i,n=1,nr,nw;
	char buf[SIZE];
	
	FILE *fpR,*fpW;
	fpR=fopen("text1.txt","rt");
	fpW=fopen("encrypted.txt","wt");
	
	while(!feof(fpR)){
		nr=fread(buf,1,SIZE,fpR);
		for(i=0; i<SIZE; i++){
			if(buf[i]>='a' && buf[i]<=('z'-n)){
				buf[i]+=n;
			}else if(buf[i]>('z'-n) && buf[i]<='z'){
				buf[i]+=(n-(26));
			}
		}
		nw=fwrite(buf,1,nr,fpW);
		if(nw!=nr){
			printf("Error in write command!\n");
			getchar();
			exit(1);
		}
	}
	
	fclose(fpR);
	fclose(fpW);
	return 0;
}
