#include <iostream>
using namespace std;
int strlen(const char c[]){
    int count = 0;
    while (c[count] != '\0')
        count++;
    return count;
}
char* strcpy(char* des,const char* sou){
    for (int i = 0; i < strlen(sou); i++){
        *(des+i) = *(sou+i);
    }
    return des;
}
char* reverse(const char* c){
    char* str = new char [strlen(c)];
    str = strcpy(str,c);
    for (int i = 0, j = strlen(c)-1; i < j; i++,j--){
        char tmp = *(str+i);
        *(str+i) = *(str+j);
        *(str+j) = tmp;
    }
    return str;
}
char* delete_char(const char* a, char c){
    char* tmp = new char[strlen(a)];
    tmp = strcpy(tmp,a);
    char* str = new char [strlen(a)];
    str = strcpy(str,a);
    int count = 0;
    for (int i = 0, j = 0; i < strlen(a);i++){
        if (*(tmp+i) == c) *(tmp+i) = '_';
        else{
            *(str+j) = *(tmp+i);
            j++;
        }
        count = i - j;
    }
    *(str + strlen(tmp) - count - 1) = '\0';
    return str;
}
char* pad_right(const char* a, int n){
    char* str = new char [strlen(a)];
    str = strcpy(str,a);

    int old_size = strlen(a);
    if (old_size < n){
        for (int i = 0; i < n - old_size; i++){
            *(str+old_size+i) = '_';
        }
    }
    return str;
}
char* pad_left(const char* a, int n){
    char* str = new char [strlen(a)];
    str = strcpy(str,a);
    int old_size = strlen(a);
    if (old_size < n){
        for (int i = n; i >= 0; i--){
            if (i < n - old_size - 1){
                *(str+i) = '_';
            }else {
                *(str+i) = *(str+i-(n-old_size-1));
            }
        }
    }
    return str;
}
char* truncate(const char* a, int n){
    char* str = new char [strlen(a)];
    str = strcpy(str,a);
    if (strlen(a) > n){
        for (int i = strlen(a) - n;i < strlen(a);i++){
            *(str+i) = '\0';
        }
    }
    return str;
}
bool is_palindrome(char* a){
    for (int i = 0, j = strlen(a) - 1; i < j; i++, j--){
        if (*(a+i) != *(a+j)) return false;
    }
    return true;
}
char* trim_left(const char* a){
    char* tmp = new char[strlen(a)];
    strcpy(tmp, a);
    char* str = new char [strlen(a)];
    str = strcpy(str,a);
    int count = 0;
    while(*(tmp+count) == '_'){
        count++;
    }
    if (count != 0){
        for (int i = 0; i < strlen(tmp);i++){
            if (i < strlen(a) - count){
                *(str+i) = *(str+strlen(a)+i);
            }else {
                *(str+i) = '\0';
             }
        }
    }
    return str;

}
char* trim_right(const char* a){
    char* tmp = new char[strlen(a)];
    strcpy(tmp, a);
    char* str = new char [strlen(a)];
    str = strcpy(str,a);
    int count = 0;
    while(*(tmp+strlen(a)-count-1) == '_'){
        count++;
    }
    if (count != 0){
        for (int i = strlen(tmp)-count; i < strlen(tmp);i++){
            *(str+i) = '\0';
        }
    }
    return str;
}
int main(){
    const char c[] = "abc";
    const char _c[] = "abcxy";
    const char c_[] = "xyabcd";

    cout << reverse(c);

     cout << delete_char(c,'d');

     cout << pad_right(c, 15);

     cout << pad_left(c,15);

     cout << truncate(c, 5);

     cout <<  if (is_palindrome(c)) cout << "YES";
     else cout << "NO";

     cout << trim_left(_c);

    cout << trim_right(c_);

    cout << cout << c << endl;

    return 0;
}
