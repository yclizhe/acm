#include <iostream>
#include <cstring>

using namespace std;
#define MAX(a,b) (a)>(b)?(a):(b)

int r,c;
int ** h;
int ** m;

int getMax(int a, int b) {
	if(m[a][b]!=0)
		return m[a][b];
	int max = 1;
	if(a>0 && h[a-1][b] < h[a][b] )
		max = MAX(getMax(a-1,b)+1,max);
	if(a<(r-1) && h[a+1][b] < h[a][b] )
		max = MAX(getMax(a+1,b)+1,max);
	if(b>0 && h[a][b-1] < h[a][b] )
		max = MAX(getMax(a,b-1)+1,max);
	if(b<(c-1) && h[a][b+1] < h[a][b] )
		max = MAX(getMax(a,b+1)+1,max);
	m[a][b] = max;
	return max;
}


int main() {
	cin >> r >> c;
	h = new int* [r];
	m = new int* [r];
	for(int i=0; i<r; i++) {
		h[i] = new int[c];
		m[i] = new int[c];
		memset(h[i],0,c*4);
		memset(m[i],0,c*4);
	}

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin >> h[i][j];
		
	int max = -1;
	max = getMax(r-1,c-1);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			if(m[i][j]==0)
				m[i][j] = getMax(i,j);
			max = MAX(max,m[i][j]);
		}
	cout << max << endl;
	return 0;
}
