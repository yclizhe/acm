#include <iostream>
#include <cstring>
using namespace std;
#define MAX(a,b) (a)>(b)?(a):(b)
int dp[1005];
int a[1005];
int main() {
	int N;
	cin >> N;
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	for(int i=0; i<N; i++)
		cin >> a[i];
	dp[0] = 1;
	int ans = 1;
	for(int i=1; i<N; i++) {
		int max = 0;
		for(int j=i-1; j>=0; j-- ) {
			if(j==max-1)
				break;
			if(a[i] > a[j])
				max = MAX(max,dp[j]);	
		}
		dp[i] = max + 1;
		ans = MAX(dp[i],ans);
		
	}
	cout << ans << endl; 
}
