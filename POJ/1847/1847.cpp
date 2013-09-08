#include <iostream>
#include <cstring>
using namespace std;
int N,A,B;
char G[105][105];
int main() {
	cin >> N >> A >> B;
	int x,y;
	memset(G,127,sizeof(G));
	for(int i=1; i<=N; i++) {
		cin >> x;
		for(int k=0; k<x; k++) {
			cin >> y;
			G[i][y] = k==0?0:1;
		}
	}
	for(int k=1; k<=N; k++)
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++) 
				if(G[i][k] + G[k][j] < G[i][j])
					G[i][j] = G[i][k] + G[k][j];
	if(G[A][B]>=127)
		cout << -1 << endl;
	else
		cout << (int)G[A][B] << endl;
			
	return 0;
}
