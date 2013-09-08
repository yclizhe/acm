#include <iostream>
#include <cstring>
using namespace std;
const char op[3] = {'+','-','.'};
char ans[20];
int numofans;
int N;
void print() {
	cout << 1;
	for(int i=2; i<=N; i++)
		cout << " " <<  ans[i-2] << " " << i;
	cout << endl;
}
void dfs(int depth, int sum, int lastnum, char lastop) {
	if(depth==N-1) {
		if(lastop=='+')
			sum += lastnum;
		else
			sum -= lastnum;
		if(sum == 0 && ++numofans <= 20) 
			print();
		
		return;
	}

	for(int i=0; i<3; i++) {
       // int psum = sum, plastnum = lastnum, plastop = lastop;
		int nsum = sum, nnum = lastnum, nop = lastop;
		ans[depth] = op[i];
		if(i<2) {
			if(lastop=='+')
				nsum = sum +lastnum;
			else
				nsum = sum -lastnum;
			nop = op[i];
			nnum = depth + 2;
		}
		else {
			if(depth < 8)
				nnum = lastnum*10 + (depth+2);
			else
				nnum = lastnum*100 + (depth+2);
		}
		if(nsum>10000000)
			continue;
		if(nnum>10000000)
			continue;
		dfs(depth+1, nsum, nnum, nop);
	}
}
int main() {
	cin >> N;
	numofans = 0;
	dfs(0,0,1,'+');
	cout << numofans <<endl;

}

