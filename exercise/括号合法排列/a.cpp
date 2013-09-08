#include <iostream>
using namespace std;

char str[1000];

void dfs(int left, int right, int n, char * str) {
	if(left == right && left == n) {
		str[2*n+1] = '\0';
		cout << str << endl;
		return;
	}
	
	if(left < n) {
		str[left+right] = '(';
		dfs(left+1, right, n, str);
	}

	if(right < n && left>right) {
		str[left+right] = ')';
		dfs(left, right+1, n, str);
	}
}

int main () {
	while(1) {
		int n;
		cin >> n;
		dfs(0,0,n,str);
	}	
}
