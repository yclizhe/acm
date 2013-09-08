#include <iostream>
#include <cstring>
using namespace std;
#define MAX(a,b) (a)>(b)?(a):(b)
int main() {
	int N;
	int dp[105][105];
	while(cin >> N) {
		if(!N)
			break;
		int a,b;
		for(int i=0; i<105; i++)
			memset(dp[i],0,105*4);
		
		for(int i=0; i<N; i++){
			cin >> a >> b;
			dp[a][b]++;
		}

		int max = 0;
		for(int i=1; i<=100; i++)
			for(int j=1; j<=100; j++) {
				int d = MAX(dp[i-1][j],dp[i][j-1]);
				dp[i][j] += d;
				max = MAX(dp[i][j],max);
			}
		cout << max << endl;
	}
	cout << "*" << endl;
	return 0;
}
