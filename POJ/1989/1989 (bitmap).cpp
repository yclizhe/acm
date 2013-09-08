#include <iostream>
#include <cstring>
//#include <set>
using namespace std;
#define MASK 0x1f
#define SHIFT  0x5
int flag[350];
void set(int x) {
	flag[x>>SHIFT] |= 1<<(x&MASK);	
}

bool test(int m) {
	int n = m/32;
	for(int i=0; i<n; i++)
		if(flag[i]!=0xffffffff)
			return false;
	int s = m%32;
	int t = 2;
	for(int i=0; i<s; i++) {
		if(!(flag[n] & t))
			return false;
		t = t << 1;
	}
	return true;
}
int main() {
	int n,m;
	cin >> n >> m;
	flag[0] = 1;
//	set<int> flag;
	int count = 0;
	while(n--) {
		int x;
		cin >> x;
		set(x);
		if(test(m)) {
			count++;
			memset(flag,0,sizeof(flag));
			flag[0] = 1;
		}
	}
	cout << ++count << endl;
}
