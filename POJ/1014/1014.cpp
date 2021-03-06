#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Min(a,b) (a)>(b)?(b):(a)
bool dp[7][120000];
int sum(int a[]) {
	int s = 0;
	for(int i=0; i<=6; i++)
		s += a[i] * i;
	return s;
}
int main() {
	int a[7];
	a[0] = 0;
	int t = 0;
	while(true) {
		scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
		int s = sum(a);
		if(s == 0)
			break;
		memset(dp,0,sizeof(dp));
		if(s%2 != 0) {
			cout << "Collection #" << ++t << ":\nCan't be divided" << endl << endl;
			continue;
		}
		else {
			s = s/2;
			for(int i=0; i<7; i++)
				dp[i][0] = true;
			for(int i=1; i<7; i++)
				for(int j=1; j<=s; j++) {
					int mk = Min(j/i,a[i]);
					for(int k=0; k<=mk; k++)
						if(dp[i-1][j-k*a[i]]) {
							dp[i][j] = true;
							break;
						}
				}
			if(dp[6][s])
				cout << "Collection #" << ++t << ":\nCan be divided" << endl << endl;
			else 
				cout << "Collection #" << ++t << ":\nCan't be divided" << endl << endl;
		}
	}
}
