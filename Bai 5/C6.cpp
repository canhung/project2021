#include<iostream>
using namespace std;

int UCLN(int a, int b)
{
	while(a * b)
	{
		if(a > b) a = a % b;
		else b = b % a;
	}
	return a + b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << UCLN(a, b);
	return 0;
}
