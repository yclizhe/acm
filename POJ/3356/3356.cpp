#include <iostream>
#include <cstring>
using namespace std;
#define MIN(a,b) (a)<(b)?(a):(b)
int dp[2][1005];
char a[1005],b[1005];
int la,lb;
int main () {
	while(cin >> la >> a >> lb >> b) {
		//memset(dp,0,sizeof(dp));
		for(int j=0; j<=lb; j++)
			dp[0][j] = j;
		int current,pre = 0;
		for(int i=1; i<=la; i++) {
			current = i%2;
			pre = (i+1)%2;
			dp[current][0] = i;
			for(int j=1; j<=lb; j++) {
				if(a[i-1] == b[j-1]) {
					dp[current][j] = MIN(dp[current][j-1]+1,dp[pre][j]+1);
					dp[current][j] = MIN(dp[current][j],dp[pre][j-1]);
				}
				else {
					dp[current][j] = MIN(dp[current][j-1]+1,dp[pre][j]+1);
					dp[current][j] = MIN(dp[current][j],dp[pre][j-1]+1);
				}
			}
		}
		cout << dp[current][lb] << endl;
	}
}
