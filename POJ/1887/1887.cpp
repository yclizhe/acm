#include <iostream>
#include <cstring>
using namespace std;
#define Max(a,b) (a)>(b)?(a):(b)
int main () {
	int h;
	int ca = 1;
	bool flag = true;
	int num = 0;
	short int dp[100000];
	short int a[100000];
	while(cin >> h) {
		if(h!=-1) {
			flag = false;
			a[num++] = h;
		}
		if(flag && h==-1)
			break; if(!flag && h==-1) {
			dp[0] = 1;
			int max = 1;
			for(int i=1; i<num; i++) {
				int m = 1;
				for(int j=0; j<i; j++)
					if(a[i]<=a[j])
						m = Max(m,dp[j]+1);
				dp[i] = m;
				max = Max(max,dp[i]);
			}
			flag = true;
			num = 0;
			cout << "Test #" << ca++ << ":" << endl;
			cout << "  " << "maximum possible interceptions: " << max << endl << endl;
			memset(a,0,sizeof(a));
			memset(dp,0,sizeof(dp));
		}

	}
	return 0;
}

