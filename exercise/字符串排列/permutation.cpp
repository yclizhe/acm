#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct ab {
	int a;
	int b;
	ab() {
		a =0;
		b = 0;
	}
	ab(int x, int y);
};
ab::ab(int x, int y) {
	
}
char str[1000];
bool swap(int k, int i, char *str) {
	if(k==i)
		return true;
	else if(str[k]==str[i])
		return false;
	else {
		str[k] = str[k]^str[i];
		str[i] = str[k]^str[i];
		str[k] = str[k]^str[i];
		return true;
	}
}
void perDFS(char *str, int k, int n) {
	if(k==n) {
		cout << str << endl;
		return;
	}
	for(int i=k; i<n; i++) {
		if(swap(k,i,str)) {
			perDFS(str, k+1, n);
		}
	}
}
int cmp(const void *a, const void *b) {
	return *(char*)a - *(char*)b;
}
int main () {
	while(cin >> str) {
		qsort(str,strlen(str),sizeof(char),cmp);
		perDFS(str,0,strlen(str));
		memset(str,0,sizeof(str));
	}
}
