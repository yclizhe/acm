#include <iostream>
#include <cstring>
using namespace std;
char dp[2][205];
char a[205],b[205],c[405];
bool DFS(int ia, int ib) {
	if(ia==-1 && ib==-1)
		return true;

	if(ia>=0 && a[ia]==c[ia+ib+1])
		if(DFS(ia-1,ib))
			return true;
	if(ib>=0 && b[ib]==c[ia+ib+1])
		if(DFS(ia,ib-1))
			return true;
	return false;
	
}
int main () {
	int n,la,lb;
	cin >> n;
	int N = n;
	while(n--) {
		memset(dp,0,sizeof(dp));
		cin >> a >> b >> c;
		la = strlen(a);
		lb = strlen(b);
		if(DFS(la-1,lb-1))
			cout << "Data set "  << N-n << ": " << "yes" << endl;
		else
			cout << "Data set "  << N-n << ": " << "no" << endl;
	}
}
