#include <iostream>
using namespace std;
int f(int n, int e) {
	if(n==1)
		return 1;
	if(e==0)
		return f(n-1,0)+f(n-1,1);
	else
		return f(n-1,0);
}
int main() {
	int N;
	cin >> N;
	int count = 0;
	while(N--) {
		int n;
		cin >> n;
		cout << "Scenario #" << ++count << ":\n" <<  f(n,0)+f(n,1) << endl << endl;
	}
	
}
