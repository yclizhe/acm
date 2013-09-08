#include <iostream>
#include <cstring>
using namespace std;
#define Max(a,b) (a)>(b)?(a):(b)
int a[5005];
int dp[5005];
int count[5005];
int main () {
	int N;
	cin >> N;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	memset(count,0,sizeof(count));
	int index = 0;
	while(N--) 
		cin >> a[index++];
	dp[0] = 1;
	count[0] = 1;
	for(int i=1; i<index; i++) {
		int max = 1;
		count[i] = 1;
		for(int j=0; j<i; j++) {
			if(a[j]>a[i]) {
				if(dp[j] + 1 > max) {
					max = dp[j] + 1;
					count[i] = count[j];
				}
				else if(dp[j]+1 == max) 
					count[i] += count[j];
			}
			else if(a[j] == a[i]) {
				max = Max(max,dp[j]);
				count[j] = 0;
			}
		}
		dp[i] = max;
	}
	int num = 0;
	int m = 0;
	for(int i=0; i<index; i++) {
		if(dp[i]>m) {
			num = count[i];
			m = dp[i];
		}
		else if(dp[i] == m)
			num += count[i];
	
	}
	cout << m << " " << num << endl;

	return 0;
}
