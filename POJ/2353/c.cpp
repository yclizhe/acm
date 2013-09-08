#include <iostream>
#include <cstring>
#include <cstdio>
int dp[105][505];
int a[105][505];
int ans[105][505];
using namespace std;
int main() {
	int M,N;
	cin >> M >> N;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(ans));
	for(int i=1; i<=M; i++)
		for(int j=1; j<=N; j++)
			scanf("%d",&a[i][j]);

	for(int j=1; j<=N; j++)
		dp[0][j] = 0;
	for(int i=1; i<=M; i++)
		dp[i][0] = (dp[i][N+1] = 0x1fffffff);

	for(int j=1; j<=N; j++)
		ans[0][j] = -1;

	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++) {
			if(dp[i-1][j] < dp[i][j-1]) {
				dp[i][j] =  a[i][j] + dp[i-1][j];
				ans[i][j] = j;
			}
			else {
				dp[i][j] =  a[i][j] + dp[i][j-1];
				ans[i][j] = j-1;
			}
		}
		for(int j=N; j>=1; j--) {
			if(dp[i][j+1]+a[i][j]<dp[i][j]) {
				dp[i][j] = dp[i][j+1] + a[i][j];
				ans[i][j] = j+1;
			}
		}
	}

	int min=0x1fffffff,minid=0;
	for(int j=1; j<=N; j++)
		if(dp[M][j]<min) {
			min = dp[M][j];
			minid = j;
		}
	int s[50000] = {0};
	int count = 0;
	int a = M, b = minid;
	s[count++] = minid;
	while(a>1) {
		if(ans[a][b] == b) {
			s[count++] = b;
			--a;
		}
		else {
			s[count++] = ans[a][b];
			b = ans[a][b];
		}
	}
	while(count--) 
		printf("%d\n",s[count]);
	return 0;
}	
