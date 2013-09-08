#include <iostream>
#include <cstring>
using namespace std;
int p[105];
int solution[4];
inline bool isOk() {
	if(p[solution[0]] == (p[solution[1]] + p[solution[2]] + p[solution[3]]))
		return true;
	else
		return false;
}
inline void print() {
	cout << "Cube = " << solution[0] << ", Triple = (";
	cout << solution[1] << "," << solution[2] << "," << solution[3]<< ")" << endl;
}

void dfs(int depth,int N) {
	if(depth == 4) {
		if(isOk())
			print();
		return;
	}
	for(int i=2; i<=N; i++) {
		if(depth>0 && i>=solution[0])
			continue;
		if(depth>1 && i<solution[depth-1])
			continue;
		if(depth>0 && (N-i)<(3-depth))
			continue;
		solution[depth] = i;
		dfs(depth+1,N);
	}
	solution[depth] = 0;
}
int main() {
	int N;
	cin >> N;
	for(int i=0; i<=N; i++)
		p[i] = i*i*i;
	dfs(0,N);
}
