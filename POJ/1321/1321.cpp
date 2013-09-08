#include <iostream>
#include <cstring>
using namespace std;
int m[10][10];
bool row[10];
bool col[10];
int solution[10];

int count;

void dfs(int depth, int n, int k) {
	if(depth==k) {
		count++;
		return;
	}
	int nextRow;
	if(depth==0)
		nextRow = 0;
	else
		nextRow = solution[depth-1]+1;
	for(int i=nextRow; i<=(n-(k-depth)); i++) {
		if(row[i])
			continue;
		for(int j=0; j<n; j++) {
			if(m[i][j] != 0 || col[j])
				continue;
			row[i] = 1;
			col[j] = 1;
			solution[depth] = i;
			dfs(depth+1,n,k);
			solution[depth] = -1;
			row[i] = 0;
			col[j] = 0;
		}
	}
}

int main() {
	int n,k;
	while(cin >> n >> k) {
		count = 0;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(solution,-1,sizeof(solution));
		if(n==-1 && k==-1)
			break;
		char c;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				cin >> c;
				m[i][j] = c=='#'?0:-1;
			}
		dfs(0,n,k);
		cout << count << endl;

	}
	return 0;
} 
