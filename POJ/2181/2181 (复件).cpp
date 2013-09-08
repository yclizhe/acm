#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
int n,a;
int main () {
	scanf("%d",&n);
	scanf("%d",&a);
	int dp1 = a;
	int dp2 = 0;
	int tdp1;
	for(int i=1; i<n; i++) {
		scanf("%d",&a);
		tdp1 = dp1;
		dp1 = MAX(dp2 + a,dp1);
		dp2 = MAX(tdp1 - a,dp2);
	}
	cout << MAX(dp1,dp2) << endl;
}
