#include <stdio.h>

struct stock_record{
	int no;
	char des[21];
	float price;
	int qty;
};

int main(){
	
	struct stock_record stk_item={12,"Not Bad.",19.95,98};
	
	printf("Please input:\n");
	printf("Item number: ");
	scanf("%d",&stk_item.no);
	getchar();
	printf("Description: ");
	gets(stk_item.des);
	printf("Price: ");
	scanf("%f",&stk_item.price);
	printf("Quantity: ");
	scanf("%d",&stk_item.qty);
	
	printf("\nStock Item:");
	printf("\nNumber: %d", stk_item.no);
	printf("\nDescription: %s", stk_item.des);
	printf("\nPrice: %.2f", stk_item.price);
	printf("\nQuantity: %d", stk_item.qty);
	
	printf("\n\n[Press ENTER to close]");
	getchar();
	getchar();
	return 0;
}
