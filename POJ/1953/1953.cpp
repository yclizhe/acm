#include <iostream>
#include <cstring>
using namespace std;
char dp[46][2];
int main() {
	int N;
	cin >> N;
	int count = 0;
	while (N--) {
		memset(dp,0,sizeof(dp));
		int n;
		cin >> n;
		dp[1][0] = 1;
		dp[1][1] = 1;
		for(int i=2; i<=n; i++) {
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
		}
		cout << "Scenario #" << ++count << ":\n" <<  dp[n][0] + dp[n][1] << endl << endl;
	}
}
