#include <stdio.h>

int main(){
	
	int RecTL[2],RecBR[2],pnt[2];
	
	printf("Enter x,y for top left: ");
	scanf("%d %d",&RecTL[0],&RecTL[1]);
	
	printf("Enter x,y for bottom right: ");
	scanf("%d %d",&RecBR[0],&RecBR[1]);
	
	printf("Enter x,y for a point: ");
	scanf("%d %d",&pnt[0],&pnt[1]);
 
	if(pnt[0]>RecTL[0] && pnt[0]<RecBR[0] && pnt[1]>RecTL[1] && pnt[1]<RecBR[1]){
		printf("\n(%d,%d) is inside the rectange\n",pnt[0],pnt[1]);
	}else{
		printf("\n(%d,%d) is outside the rectange\n",pnt[0],pnt[1]);
	}
	
	printf("\n[Press ENTER to close]");
	getchar();
	getchar();
	return 0;
}
