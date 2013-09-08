#include <iostream>
#include <cstring>
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
int arrive[1500];
int n,t,m;
int dp[2][1500];
int main() {
	int c;
	cin >> c;
	while(c--) {
		cin >> n >> t >> m;
		for(int i=0; i<m; i++)
			cin >> arrive[i];
		memset(dp,127, sizeof(dp));
		dp[0][0] = 0;
		dp[1][0] = 0;
		for(int i=1; i<=m; i++)
			for(int j=i-1; j>=i-n && j>=0; j--) {
				int tmp = MAX(dp[0][j],arrive[i-1]);
				tmp += t*2;
				int tmp2 = dp[1][j] + 1;
				if(tmp < dp[0][i]) {
					dp[0][i] = tmp;
					dp[1][i] = tmp2;
				}
				else if(tmp == dp[0][i] && tmp2<dp[1][i])
					dp[1][i] = tmp2;
			}

		cout << dp[0][m]-t << " " << dp[1][m]  << endl;
	}
}

