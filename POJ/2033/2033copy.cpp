#include <iostream>
#include <cstring>
using namespace std;
int decode(char a, char b) {
	int x = 10*(a-'0') + b-'0';
	if(x>=10 && x<=26)
		return 1;
	else
		return 0;
}

int dp[5000];
char str[5000];
int main() {
	while(cin >> str) {
		if(strcmp(str,"0") == 0)
			break;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		if(str[1] == '0')
			dp[1] = 1;
		else
			dp[1] = 1 + decode(str[0],str[1]);
		int len = strlen(str);
		for(int i=2; i<len; i++)
			if(str[i] == '0')
				dp[i] = dp[i-2];
			else
				dp[i] = dp[i-1]+dp[i-2]*decode(str[i-1],str[i]);
		cout << dp[len-1] << endl;
		
	}
}
