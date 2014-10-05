#include <iostream>

using namespace std;

void getNums(int&,int&);

int main(){
	
	int num1=0,num2=0;

	getNums(num1,num2);
	
	cout<<"You entered: "<<endl<<num1<<endl<<num2;
	
	getchar();
	getchar();
	
	return 0;
}

void getNums(int &n1, int &n2){
	cout<<"Enter value for 1st number: ";
	cin>>n1;
	cout<<"Enter value for 2nd number: ";
	cin>>n2;
	
}
