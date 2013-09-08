#include <iostream>
#include <cstring>
using namespace std;
#define INF 1<<31
int getMax(int a[], int n) {
	int sum = 0;
	int max = INF;
	int m = -10000;
	for(int i=0; i<n; i++) {
		if(sum >=0)
			m = sum + a[i];
		else
			m = a[i];
		sum += a[i];
		
		if(m>max)
			max = m;
	}
	return max;
}
int main() {
	int N;
	cin >> N;
	int **ma = new int* [N];
	for(int i=0; i<N; i++) {
		ma[i] = new int[N];	
		memset(ma[i],0,4*N);
	}
	int NN = N*N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> ma[i][j];
	int max = INF;
	for(int i=0; i<N; i++) {
		int *b = new int[N];
memset(b,0,4*N);
		for(int x=0; x<N; x++)
			b[x] = 0;
		for(int j=i; j<N; j++) {
			for(int k=0; k<N; k++) {
				b[k] += ma[j][k];	
			}
			int m = getMax(b,N);
			if(m>max)
				max = m;
		}
		delete [] b;
	}
	cout << max << endl;
return 0;
}
