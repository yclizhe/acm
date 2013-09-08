#include <iostream>
#include <cstring>
using namespace std;
#define MAX(a,b) (a)>(b)?(a):(b)
int main() {
	int **dp;
	char a[10000],b[10000];
	while(cin >> a >> b) {
		int la = strlen(a);
		int lb = strlen(b);
		dp = new int* [la+1];
		for(int i=0; i<=la; i++) {
			dp[i] = new int[lb+1];
			memset(dp[i],0,4*(lb+1));
		}
		for(int i=1; i<=la; i++)
			for(int j=1; j<=lb; j++) {
				int max = 0;
				if(a[i-1]==b[j-1])
					max = dp[i-1][j-1]+1;
				else
					max = MAX(dp[i][j-1], dp[i-1][j]);
				dp[i][j] = max;
			}
		cout << dp[la][lb] << endl;
		for(int i=0; i<=la; i++)
			delete[] dp[i];
        delete[] dp;

	}
	return 0;
}

