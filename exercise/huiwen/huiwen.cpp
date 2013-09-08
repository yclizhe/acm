#include <iostream>
#include <cstring>
using namespace std;
bool f(char * str) {
	int i = 0;
	int j = strlen(str)-1;
	while(i<j)
		if(str[i++]!=str[j--])
			return false;
	return true;
	
}
int main() {
	char str[255];
	while(cin >> str)
		cout << f(str) << endl;
}
