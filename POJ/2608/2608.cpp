#include <iostream>
#include <cstring>
using namespace std;
char str[20];
int ans[20];
char hash[26] = {0,1,2,3,0,
		1,2,0,0,2,
		2,4,5,5,0,
		1,2,6,2,3,
		0,1,0,2,0,2};
inline void print(int len) {
	for(int i=0; i<len; i++) {
		if(ans[i] == 0)
			continue;
		if(i==0)
			cout << ans[i];
		else if(ans[i]!=ans[i-1])
			cout << ans[i];
	}
	cout << endl;
}

int main() {
	while(cin >> str) {
		int len = strlen(str);
		for(int i=0; i<len; i++) 
			ans[i] = hash[str[i]-'A'];
		print(len);
	}
}
