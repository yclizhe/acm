#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef struct state {
	int a,b,pre;
	state(int x, int y, int p) {
		a = x;
		b = y;
		pre = p
	}
}state;

bool isOk(state s,int N) {
	if(s.a==N || s.b==N)
		return true;
	else
		return false;
}

void print(Vector<state> v) {

}

void bfs(int A, int B, int N) {
	vector<state> v;
	queue<state> q;
	state s(0,0,-1);
	q.push(state);
	while(!q.empty()) {
		state cur = q.front();
		q.pop();
		if(isOk(cur,N))
			print();

	}
}

int main() {
	int A,B,N;
	while(cin >> A,B,N) {
		
	}
}
