#include <iostream>

using namespace std;

int main( )
{
   int a[4] = {1,2,3,4};
   int *cp = a;
   for (int i = 0; i < 4; i++) {
      cout << (void*) (cp+i) << " : " << (*(cp+i)) << endl;
   }
   return 0;
}

#include <iostream>

using namespace std;

int main( )
{
   double a[4] = {1,2,3,4};
   double *cp = a;
   for (int i = 0; i < 4; i++) {
      cout << (void*) (cp+i) << " : " << (*(cp+i)) << endl;
   }
   return 0;
}

