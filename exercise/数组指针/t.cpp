#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char *const str = "abc";
	str[1] = 'x';
	int a[3][4];
	memset(a,10,sizeof(a));
	a[2][3] = 11;
	int (*p)[4];
	p = a;
	cout << p[2][3];
}
