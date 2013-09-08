#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
using namespace __gnu_cxx;
#define MASK 0x1f
#define SHIFT  0x5
bool flag[10001];
int main() {
	int n,m;
	memset(flag,0,sizeof(flag));
	cin >> n >> m;
	int count = 0;
	int t = 0;
	while(n--) {
		int x;
		//cin >> x;
		scanf("%d",&x);
		if(!flag[x]){
			t++;
		flag[x] = true;
		if(t==m) {
			count++;
			memset(flag,0,sizeof(flag));
			t = 0;
		}
		}
	}
	cout << ++count << endl;
}
