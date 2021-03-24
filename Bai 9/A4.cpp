#include <iostream>
using namespace std;
int main(){
    int* p = new int;
    {
        int x = 5;
        *p = x;
        cout << *p << endl;
        delete p;
        cout << *p << endl; // p trỏ đến biến địa phương. sau khi giải phóng thì *p nhận 1 giá trị rác 
    }
    //delete p; // giải phóng p tại đây
    cout << *p ;


    return 0;
}