#include <iostream>
#include <cstring>
using namespace std;

#define Min(a,b) (a)>(b)?(b):(a)
#define Max(a,b) (a)>(b)?(a):(b)
int main() {
	int cash, n;
	while(true) {
		cash = -1;
		n = -1;
		cin >> cash >> n;
		if( n==0){
			cout << 0 << endl;
			continue;
		}
		int* N = new int[n];
		int* D = new int[n];
		int** m = new int* [n+1];
		for(int i=0; i<n; i++){
			cin >> N[i] >> D[i];
			m[i] = new int[cash+1];
		}
		m[n] = new int[cash+1];

		for(int j=0; j<cash+1; j++)
			m[0][j] = 0;

		for(int i=0; i<n; i++)
			for(int j=0; j<cash+1; j++) {
				int max = 0;
				int min = Min(N[i],j/D[i]);
				for(int k=0; k<=min; k++)
					max = Max(max, m[i][j-k*D[i]]+k*D[i]);
				m[i+1][j] = max;
			}
		
		cout << m[n][cash] << endl;
		delete N;
		delete D;
		delete m;
	}

}
