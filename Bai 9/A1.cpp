#include <iostream>
#include <cstring>
using namespace std;
char* concat(const char* a, const char* b) {
    int size = strlen(a) + strlen(b);
    char* cat = new char[size];
    for (int i = 0; i < strlen(a); i++){
        *(cat+i) = *(a + i);
    }
    strcat(cat, b);
    return cat;
}
int main(){
    const char* a = "hunghung";
    const char* b = "  can";
    cout << concat(a, b);
    return 0;
}
