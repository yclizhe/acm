#include <iostream>
#include <cstring>
using namespace std;
#define Min(a,b) (a)>(b)?(b):(a)
int rows[6];
int rowN;
int N;
bool visited[35];
int solution[6][35];
int ans;
void getPos(int depth, int& row, int& col) {
	for(int i=0; i<rowN; i++)
		for(int j=0; j<rows[i]; j++) {
			if(depth-- == 0) {
				row = i;
				col = j;
				return;
			}
		}
}
void dfs(int depth) {
	if(depth == N) {
		ans ++;
		return;
	}
	int max=50, row, col;
	if(depth==0) {
		max = N-1;
		row = 0;
		col = 0;
		}
	else {
		getPos(depth,row,col);
		if(row>0)
			max = Min(max,solution[row-1][col]-1);
		if(col>0)
			max = Min(max,solution[row][col-1]-1);
	}
			for(int i=0; i<=max; i++) {
			if(visited[i])
				continue;
			if(i<rows[row]-1-col)
				continue;
			visited[i] = true;
			solution[row][col] = i;
			dfs(depth+1);
			visited[i] = false;
			solution[row][col] = -1;
		}

}
int main() {
	while(cin >> rowN) {
		ans = 0;
		memset(rows,0,sizeof(rows));
		memset(visited,0,sizeof(visited));
		memset(solution,0,sizeof(solution));
		if(rowN == 0)
			break;
		N = 0;
		for(int i=0; i<rowN; i++) {
			cin >> rows[i];
			N += rows[i];
		}
		ans = 0;
		dfs(0);
		cout << ans << endl;
	}
}

