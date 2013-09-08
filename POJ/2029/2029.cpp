#include <iostream>
#include <cstring>
using namespace std;
int getMax(int * m, int w, int W) {
	int max = 0;
	int sum = 0;
	for(int i=1; i<=W; i++) {
		if(i<=w) {
			max += m[i];
			sum += m[i];
		}
		else {
			sum = sum + m[i] - m[i-w];
			if(sum > max)
				max = sum;
		}
	}	
	return max;
}

int map[100][100];
int m[100];
int main () {
	int n,W,H,w,h;
	while(true) {
		cin >> n;
		if(!n)
			break;
		cin >> W >> H;
		memset(map,0,sizeof(map));
		while(n--) {
			int x,y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		cin >> w >> h;
		
		memset(m,0,sizeof(m));
		for(int j=1; j<=W; j++)
			for(int i=1; i<=h; i++)
				m[j] += map[i][j];

		int max = getMax(m,w,W);
		for(int i=h+1; i<= H; i++) {
			for(int j=1; j<=W; j++) 
				m[j] = m[j] + map[i][j] - map[i-h][j];
			
			int ma = getMax(m,w,W);
			if(max < ma)
				max = ma;
		}
		cout << max << endl;
	}
}
