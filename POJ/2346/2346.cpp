#include <iostream>
#include <cstring>
using namespace std;
int dp[5][50];
int main() {
	int N;
	while(cin >> N) {
	int n = N/2;
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=9*i; j++)
			for(int k=0; k<=j && k<=9; k++) 
				dp[i][j] += dp[i-1][j-k];
			
	int sum = 0;
	if(N==0) 
		cout << 0 << endl;
	
	else {
		for(int j=0; j<=n*9; j++)
			sum += dp[n][j]*dp[n][j];
		cout << sum << endl;
	}
	}
	return 0;
}

