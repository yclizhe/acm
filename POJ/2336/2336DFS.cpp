#include <iostream>
#include <cstring>
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
bool visited[1500];
int arrive[1500];
int n,t,m;
int trips, times;
void dfs(int mTr, int mTi, int num ) {
	if(num == m) {
		trips = MIN(trips, mTr);
		times = MIN(times, mTi);
		return;
	}
	for(int i=1; i<=n && num+i<=m; i++) {
		int getoff = MAX(mTi, arrive[num+i-1]);
		dfs(mTr+1, getoff+2*t, num+i);
	}


}
int main() {
	int c;
	cin >> c;
	while(c--) {
		cin >> n >> t >> m;
		for(int i=0; i<m; i++)
		cin >> arrive[i];
		trips = 1<<30;
		times = 1<<30;
		dfs(0,0,0);
		cout << times-t << " " << trips  << endl;
	}
}

