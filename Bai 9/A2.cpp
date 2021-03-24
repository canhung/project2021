#include <iostream>
using namespace std;
int main()
{
    int* p = new int;
    int* p2 = p; // thất thoát bộ nhớ. không thể thu hồi. 2 con trỏ tới 1 địa chỉ, không kiểm soát đc
    *p = 10;
    delete p;
    *p2 = 100;
    cout << *p2;
    delete p2;
    return 0;
}
