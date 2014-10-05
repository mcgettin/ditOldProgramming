using namespace std;
#include <iostream>

void change (double &r, double s);

int main ()
{
   double k, m;

   k = 3;
   m = 4;

   change (k, m);

   cout << k << ", " << m << endl;        // Displays 100, 4.

   cout << endl << "[Press ENTER to close]";
   getchar();
   return 0;
}


void change (double &r, double s){
   r = 100;
   s = 200;
}
