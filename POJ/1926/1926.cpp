#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define Abs(a) (a)>0?(a):(-(a))
float m[101][101];
float a[101];
float b[101];
void mm(int n) {
	memset(b,0,sizeof(b));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			b[i] += a[j]*m[j][i];
}

bool isEnd(int n) {
	bool flag = true;
	for(int i=1; i<=n; i++)
		if(Abs(b[i]-a[i]) >= 0.00001) {
			a[i] = b[i];
			flag = false;
		}
		return flag;
}

void norm(int n) {
	for(int i=1; i<=n; i++) {
		float sum  = 0;
		for(int j=1; j<=n; j++)
			sum += m[i][j];
		for(int j=1; j<=n; j++)
			m[i][j] = m[i][j]/sum;
	}
}
int main () {
	int N;
	cin >> N;
	while(N--) {
		int v,e;
		cin >> v >> e;
		memset(m,0,sizeof(m));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1; i<=v; i++)
			cin >> a[i];
		int x,y;
		for(int j=0; j<e; j++) {
			cin >> x >> y;
			m[x][y] = 1;
			m[y][x] = 1;
		}
		norm(v);
		mm(v);
		while(!isEnd(v)) 
			mm(v);
		for(int i=1; i<=v; i++)
			cout << fixed << setprecision(3) << a[i] << endl;
		cout << endl;
		

	}
	return 0;
}

