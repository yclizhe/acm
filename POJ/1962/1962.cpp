#include <iostream>
#include <cstring>
using namespace std;
#define Abs(a) a>0?(a):(-(a))
int parent[20001];
int length[20001];
void reset(int n) {
	memset(parent,0,sizeof(parent));
	for(int i=1; i<=n; i++){ 
		parent[i] = -1;
		length[i] = 0;
	}
}

int find(int x) {
	if(parent[x]<0)
		return x;
	else {
		int r = find(parent[x]);
		length[x] += length[parent[x]];
		parent[x] = r;
		return r;
	}
}

void merge(int x, int y) {
	int l;
	int rx = find(x);
	int ry = find(y);
	if(rx==ry) return;
	int num = parent[rx] + parent[ry];
	if(parent[rx]<parent[ry]) {
		parent[ry] = rx;
		parent[rx] = num;
	}
	else {
		parent[rx] = ry;
		parent[ry] = num;
	}

}

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		reset(n);
		char command;
		while(cin >> command) {
			if(command=='E') {
				int x;
				cin >> x;
				find(x);
				cout << length[x] << endl;
			}
			else if(command=='I') {
				int x,y;
				cin >> x >> y;
				parent[x] = y;
				length[x] = Abs(x-y)%1000;
			}
			else
				break;
		}

	}
	
}
