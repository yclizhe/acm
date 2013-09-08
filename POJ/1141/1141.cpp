#include <iostream>
#include <cstring>
using namespace std;
char str[105];
int dp[105][105];
int ans[105][105];
bool match(int i, int j) {
    char a = str[i];
    char b = str[j];
	if(a == '(' && b == ')')
		return true;
	else if(a == '[' && b==']')
		return true;
	else
		return false;
}

void output(int i, int j) {
	if(i>j)
		return;
	if(i==j) {
		if(str[i] == '(' || str[i]==')')
			cout << "()";
		else
			cout << "[]";
		return;
	}
	if(ans[i][j]==-1) {
		cout << str[i];
		output(i+1,j-1);
		cout << str[j];
		return;
	}
	else {
		output(i,ans[i][j]);
		output(ans[i][j]+1,j);
		return;
	}
}
int main() {
	cin.getline(str,100);
	int n = strlen(str);
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(ans));
	for(int i=0; i<n; i++)
		dp[i][i] = 1;
	for(int x=1; x<n; x++)
		for(int i=0; i<n-x; i++) {
			int j = i+x;
			dp[i][j] = 1 << 30;
			if(match(i,j)) {
					dp[i][j] = dp[i+1][j-1];
					ans[i][j] = -1;
			}
			for(int k=i; k<j; k++)
				if(dp[i][k] + dp[k+1][j] < dp[i][j]) {
					dp[i][j] = dp[i][k]+dp[k+1][j];
					ans[i][j] = k;
				}
		}
	output(0,n-1);
	cout << endl;
}

