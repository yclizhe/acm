#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
struct node {
	int x,y,p;
	node(int a, int b, int c) {
		x = a; y = b;
		p = c;	
	}
	friend bool operator<(const node x,const node y) {
		return x.p > y.p; 
	}
};
set<node> s;
inline int abs(int x, int px) {
	return x>px?x-px:px-x;
}
int dis(int px, int py, int x, int y) {
	return abs(px,x) + abs(py,y);
}
int main() {
	int N,m,n,k;
	cin >> N;
	while(N--) {
		s.clear();
		cin >> m >> n >> k;
		int x;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				cin >> x;
				if(x>0) {
					node no(i,j,x);
					s.insert(no);
				}

			}
		int curT = 0, reP = 0;
		set<node> :: iterator it;
		int px, py;
		for(it=s.begin(); it!=s.end(); it++) {
			if(it==s.begin()) { 
				curT = 1 + it->x + 1;
			}
			else 
				curT += dis(px, py, it->x, it->y) + 1;
			
			if(curT + it->x + 1 > k)
				break;
			else { 
				px = it->x;
				py = it->y;
				reP+=it->p;
			}
		}
		cout << reP << endl;
	}
}
