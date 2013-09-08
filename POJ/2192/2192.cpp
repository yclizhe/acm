#include <iostream>
#include <cstring>
using namespace std;
char dp[2][205];
char a[205],b[205],c[405];
int main () {
	int n,la,lb;
	cin >> n;
	int N = n;
	while(n--) {
		memset(dp,0,sizeof(dp));
		cin >> a >> b >> c;
		la = strlen(a);
		lb = strlen(b);
		int cur,pre;
		for(int j=1; j<=lb; j++) {
			if(b[j-1] == c[j-1])
				dp[0][j] = 1;
			else
				break;
		}
		bool flag = true;
		for(int i=1; i<=la; i++) {
			cur = i%2;
			pre = (i+1)%2;
			if(flag && a[i-1] == c[i-1])
				dp[cur][0] = 1;
			else {
				dp[cur][0] = 0;
				flag = false;
			}
			for(int j=1; j<=lb; j++) {
				if(a[i-1] == b[j-1] && a[i-1] == c[i+j-1])	
					dp[cur][j] = dp[pre][j] | dp[cur][j-1];
				else if(a[i-1]==c[i+j-1]) 
					dp[cur][j] = dp[pre][j];	
				else if(b[j-1]==c[i+j-1])
					dp[cur][j] = dp[cur][j-1];
				else
					dp[cur][j] = 0;
			}
		}
		char re[2][5] = {"no","yes"};
		cout << "Data set "  << N-n << ": " << re[dp[cur][lb]] << endl;
	}
}
