#include <iostream>

using namespace std;
void fx(int value)
{
   int x;
   x = value;
   cout << &x << endl;
}
void gy(int value)
{
   int y;
   cout << &y;

}
int main()
{
   fx(7);
   gy(11);
   return 0;
}
/*Địa chỉ của biến x và biến y là giống nhau vì vị trí của stack frame cho hàm f khi nó chạy trùng
với vị trí của hàm g khi nó được gọi
 Bắt đầu trên đỉnh stack của hàm main, cả hai hàm fx và gx
cùng có 1 tham số kiểu int, cùng kiểu trả về, x và y cùng là biến địa phương đầu tiên của hàm, do
đó trình biên dịch xếp x và y ở cùng một địa chỉ.*/
