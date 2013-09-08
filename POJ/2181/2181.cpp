#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
int n,a,pre;
int main () {
	scanf("%d",&n);
	scanf("%d",&pre);
	int add = 0xffffffff;
	int max = 0;
	for(int i=1; i<n; i++) {
		scanf("%d",&a);
		if(a<pre && add) {
			max = max + pre;
			add =  ~add;
		}

		else if(a>pre && !add) {
			max = max - pre;
			add = ~add;
		}
		pre = a;

	}
	if(add)
		max += pre;
	cout << max << endl;
}

