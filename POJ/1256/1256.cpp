#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
char solution[15];
char a[15];
int len;

bool cmp1(char x, char y) {
	if(tolower(x) == tolower(y))
		return x<y;
	else
		return tolower(x)<tolower(y); }

struct cmp{
bool operator()(const char* x, const char* y)const {
	while(*x) {
		if(cmp1(*x,*y) || cmp1(*y,*x))
			return cmp1(*x,*y);
		x++;
		y++;
	}
	return false;
}
};

set<char*, cmp> output;

inline bool swap1(int x, int y) {
	if(x==y)
		return true;
	else if(a[y-1] == a[y])
		return false;
	else {
		a[x] = a[x]^a[y];
		a[y] = a[x]^a[y];
		a[x] = a[x]^a[y];
		return true;
	}
}
void dfs(int depth) {
	if(depth ==  len) {
		char *str = new char[15];
		strcpy(str,a);
		output.insert(str);
		return;
	}

	bool flag[150];
	memset(flag,0,sizeof(flag));
	for(int i=depth; i<len; i++) {
	//	if(i==depth)
	//		dfs(depth+1);
	if(depth==1)
	int x = 1;
		if(swap1(depth,i)) {
			dfs(depth+1);
			if(i!=depth) {
                a[i] = a[i]^a[depth];
                a[depth] = a[i]^a[depth];
                a[i] = a[i]^a[depth];
			}
		}

	}

}
int main() {
	int N;
	cin >> N;
	while(N--) {
		scanf("%s",a);
		len = strlen(a);
		sort(a,a+len,cmp1);
		dfs(0);
		set<char*>::iterator it;
		for(it=output.begin(); it!=output.end(); it++)
			printf("%s\n",*it);
		output.clear();
	}
}

