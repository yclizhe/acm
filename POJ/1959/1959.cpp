#include <iostream>
#include <cstring>
using namespace std;
int *** dp;
int s[126];
int main () {
	s[0] = 0;
	int count = 1;
	s[61] = 25;
	s[62] = 50;
	for(int i=1; i<=3; i++)
		for(int j=1; j<=20; j++)
			s[count++] = i*j;
	for(int i=63; i<=125; i++)
		s[i] = s[i-63]*2;
	int N;
	cin >> N;
	int c = 0;
	while(N--) {
		int n;
		cin >> n;
		dp = new int** [126];
		for(int i=0; i<126; i++) {
			dp[i] = new int*[n+1];
			for(int j=0; j<n+1; j++) {
				dp[i][j] = new int[4];
				memset();
			}
		}
		for(int i=0; i<126; i++)
			dp[i][0] = 1;

		for(int i=1; i<126; i++) 
			for(int j=1; j<=n; j++) {
				if(s[i]>j)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j] + dp[i-1][j-s[i]];
			}
		int sum = 0;
		for(int i=0; i<63; i++)
			for(int j=0; j<63; j++)
				for(int k=0; k<63; k++)
					if(s[i]+s[j]+s[k] == n)
						sum++;
		cout << "Scenario #" << ++c << ":\n" << sum << endl << endl;
	}
}
