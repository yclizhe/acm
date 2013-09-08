#include <iostream>
using namespace std;
#define MAX(a,b) (a)>(b)?(a):(b)
int main() {
	int n;
	cin >> n;
	int** d =  new int* [n];
	int** m =  new int* [n];
	for(int i=0; i<n; i++) {
		d[i] = new int[i+1];
		m[i] = new int[i+1];
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++)
			cin >> d[i][j];

	int max = 0;
	for(int i=n-1; i>=0; i--)
		for(int j=i; j>=0; j--) {
			if(i==n-1)
				m[i][j] = d[i][j];
			else 
				m[i][j] = MAX(d[i][j]+m[i+1][j],d[i][j]+m[i+1][j+1]);

			if(m[i][j] > max)
				max = m[i][j];
		}
	cout << max << endl;

}
