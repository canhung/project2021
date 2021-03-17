#include <iostream>

using namespace std;

int getLength(char a[])
{
    int i = 0;
    while (*(a+i) != '\0'){
        i++;
    }
    return i;
}

char* reverse(char a[], int l)
{
    for (int i = 0; i < l/2; i++){
        swap(*(a+i),*(a+l-i-1));
    }
    return a;
}

char* delete_char(char a[], char c, int l)
{
    for (int i = 0; i < l; i++){
        if (*(a+i) == c){
            l--;
            for (int j = i; j < l; j++){
                a[j] = a[j+1];
            }
            i--;
        }
    }
    a[l] = '\0';
    return a;
}

char* pad_right(char a[], int n, int l)
{
    if (l >= n) return a;
    for (int i = l; i < n; i++){
        *(a+i) = ' ';
    }
    return a;
}

char* pad_left(char a[], int n, int l)
{
    if (l >= n) return a;
    for (int i = n-l; i < n; i++){
        *(a+i) = *(a+i-n+l);
    }
    for (int i = 0; i < n-l; i++){
        *(a+i) = ' ';
    }
    return a;
}

char* truncate(char a[], int n, int l)
{
    if (l <= n) return a;
    a[n] = '\0';
    return a;
}

bool is_palindrome(char a[], int l)
{
    for (int i = 0; i < l/2; i++){
        if (*(a+i) != *(a+l-i-1)) return false;
    }
    return true;
}
char* trim_left(char a[], int l)
{
    if (a[0] != ' ') return a;
    int i = 1;
    while (a[i] == ' '){
        i++;
    }
    for (int j = 0; j < l-i; j++){
        a[j] = a[l-i-1];
    }
    a[l-i] = '\0';
    return a;
}

char* trim_right(char a[], int l)
{
    if (a[l-1] != ' ') return a;
    int i = 1, j = l-2;
    while (a[j] == ' '){
        i++;
        j--;
    }
    a[l-i] = '\0';
    return a;
}

int main()
{
    char *a = new char [50];
    cin >> a;
    int l = getLength(a);
    char c;
    //cin >> c;
    int n;
    //cin >> n;
}
