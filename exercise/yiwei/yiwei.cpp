#include <iostream>
using namespace std;
int main() {
	int a = 1<<31;
	int y = a<<1;
	cout << a << endl;
	cout << y << endl;
	unsigned int b = 1<<31;
	cout << b << endl;
	int x = 0x80000001;
	x = x<<1;
	cout << x << endl;
}
