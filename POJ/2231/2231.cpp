#include <iostream>
#include <algorithm>
using namespace std;
long long sum;
int pos[10005];
int main() {
	int N;
	cin >> N;
	sum = 0;
	for(int i=0; i<N; i++) 
		cin >> pos[i];
	sort(pos,pos+N);
	for(int i=0; i<N; i++)
		sum += (long long)(pos[i]-pos[i-1]) * i * (N-i);
	
	cout << (sum << 1) << endl;
}
