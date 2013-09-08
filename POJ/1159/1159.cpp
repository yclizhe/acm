#include <iostream>
#include <cstring>
using namespace std;
#define str1(x) str[x]
#define str2(x) str[len-1-(x)]
#define MAX(a,b) (a)>(b)?(a):(b)

short dp[2][5001];
int main() {
	int len;
	cin >> len;
	char * str = new char[len+1];
	cin >> str;
	memset(dp,0,sizeof(dp));
	int fi = len+1;
	int fj = len+1;
	for(int i=0; i<len; i++) {
		if(str1(i) == str2(0)) {
			fi = i;
			break;
		}	
	}
	for(int j=0; j<len; j++) {
		if(str1(0) == str2(j)) {
			fj = j;
			break;
		}	
	}
//	for(int i=fi; i<len; i++)
//		dp[i][0] = 1;
	for(int j=fj; j<len; j++)
		dp[0][j] = 1;

	int pre = 0;
	int cur = 1;
	for(int i=1; i<len; i++) {
		if(i>=fi)
			dp[cur][0] = 1;
		cur = i%2;
		pre = (i+1)%2;
		for(int j=1; j<len; j++) {
			if(str1(i)==str2(j))
				dp[cur][j] = dp[pre][j-1]+1;
			else {
				dp[cur][j] = MAX(dp[cur][j-1],dp[pre][j]);
			}
		}
	}
	cout << len-dp[cur][len-1] << endl;

}
