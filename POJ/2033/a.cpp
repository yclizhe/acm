#include <iostream>
using namespace std;
int main () {
	char str[100];
	while(cin >> str) {
		char *temp = str;
		int len = 0;
		while(*temp) {
			cout << *temp++;
			len ++;
		}
		cout << len << endl;
	}
}
