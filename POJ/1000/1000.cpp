#include "iostream"
using namespace std;
int main() {
	int a,b;
	string str = "abc";
	int c = str.length();
	cout << c;
//	int c = strlen(str);
	while (cin >> a >> b)
		cout << a+b << endl;
	return 0;
}
