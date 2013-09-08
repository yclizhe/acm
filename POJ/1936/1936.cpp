#include <iostream>
#include <cstring>
using namespace std;
char a[100001];
char b[100001];
bool **dp;
int main () {
	while(cin >> a >> b) {
		int la = strlen(a);
		int lb = strlen(b);
		dp = new bool* [la];
		for(int i=0; i<la; i++) {
			dp[i] = new bool[lb];
			memset(dp[i],0,lb);
		}
		bool flag = false;
		for(int j=0; j<lb; j++) {
			if(flag)
				dp[0][j] = true;
			else if(a[0] == b[j]) {
				flag = true;
				dp[0][j] = true;
			}
		}

		for(int i=1; i<la; i++)
			for(int j=1; j<lb; j++) {
				if(dp[i][j-1])
					dp[i][j] = true;
				else if(dp[i-1][j-1] && a[i]==b[j])
					dp[i][j] = true;
			}
		const char * re;
		if(dp[la-1][lb-1])
			re = "Yes";
		else 
			re = "No";
		cout << re << endl;

		for(int i=0; i<la; i++) 
			delete[] dp[i];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));


	}	
	return 0;
}
