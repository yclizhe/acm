#include <iostream>
#include <cstring>
using namespace std; 
#define C(a) (a-'0')
int atoi(char * str) {
	int n = strlen(str);
	int m = 0;
	for(int i=0; i<n; i++)
		m = m*10+C(str[i]);
	return m;
}
int main() {
	char str[255];	
	while(cin >> str)
		cout << atoi(str) << endl;
	return 0;
}
