#include <iostream>
#include <cstring>
using namespace std;
int ** dp;
int main() {
	int N;
	cin >> N;
	while(N--) {
		int m,n;
		cin >> m >> n;
		dp = new int* [m+1];
		for(int i=0; i<m+1; i++) {
			dp[i] = new int [n+1];
			memset(dp[i],0,4*(n+1));
		}

		for(int i=0; i<m+1; i++)
			dp[i][0] = 0;
		for(int j=0; j<n+1; j++)
			dp[0][j] = 1;

		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++) {
				if(i<j)
					dp[i][j] = dp[i][i];
				else 
					dp[i][j] = dp[i-j][j] + dp[i][j-1];
			}
		cout << dp[m][n] << endl;
	}
}
