#include <iostream>
#include <cstring>
using namespace std;
int a[8005];
int c[8005];
int ans[8005];
int lowbit(int x) {
	return x & (-x);
}
int sum(int n) {
	int s = 0;
	while(n>0) {
		s += c[n];
		n -= lowbit(n);
	}
	return s;
}
void change(int i, int num, int max) {
	while(i<=max) {
		c[i] += num;
		i += lowbit(i);
	}
}
int binarysearch(int x, int s, int e) {
	if(s==e)
		return s;
	int m = (s+e)>>1;
	int xm = m - sum(m);
	if(xm < x)
		return binarysearch(x,m+1,e);
	else //此处注意，因为相等时并不一定正确，需要确保压缩到只剩一个位置时
		return binarysearch(x,s,m);
}
int main() {
	int N;
	cin >> N;
	memset(c,0,sizeof(c));
	a[0] = 0;
	for(int i=1; i<N; i++) 
		cin >> a[i];
	for(int i=N-1; i>=0; i--) {
		int x = binarysearch(a[i]+1, 1+a[i], N);	
		ans[i] = x;
		change(x,1,N);
	}
	for(int i=0; i<N; i++)
		cout << ans[i] << endl;
}
