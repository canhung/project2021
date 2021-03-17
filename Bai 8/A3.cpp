#include <iostream>

using namespace std;

void swap_pointers(char** x, char** y)
{
   char *tmp;
   tmp = *x;
   *x = *y;
   *y = tmp;
}
int main()
{
   char *a = "I should print second";
   char *b = "I should print first";

   char **p1 = &a;
   char **p2 = &b;

   swap_pointers(p1,p2);
   cout << "s1 is " << *p1 << endl;
   cout << "s2 is " << *p2 << endl;
   return 0;
}
