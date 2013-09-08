#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define Max(a,b) (a)>(b)?(a):(b)
int a[100000];
int dp;
int sum;
int main () {
	int n,f;
	cin >> n >>  f;
	memset(a,0,sizeof(a));
	int tmp = 0;
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
		if(i<f)
			tmp += a[i];
	}

	int count = f;
	sum = tmp;
	dp = sum;
	int max = sum*1000/f;
	for(int i=f; i<n; i++) {
		sum = sum + a[i] - a[i-f];
		int pre = (dp+a[i])*1000/(count+1);
		int cur = sum*1000/f;
		if(pre > cur) {
			count++;
			dp = dp + a[i];
			max =  Max(max,pre);
		}
		else {
			count = f;
			dp = sum;
			max = Max(max,cur);
		}
	}
	cout << max << endl;

}
