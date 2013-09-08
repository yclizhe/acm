#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
#define DIS(a,b) ((a)>(b)?(a-b):(b-a))
long long dp;
int pos[10005];
int main() {
	int N;
	cin >> N;
	dp = 0;
	for(int i=0; i<N; i++) {
		cin >> pos[i];
		for(int j=0; j<i; j++)
			dp += (long long)abs(pos[i]-pos[j]);
	}
	cout << (dp<<1) << endl;
	
}
