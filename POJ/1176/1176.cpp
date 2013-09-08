#include <iostream>
#include <set>
#include <cstring>
using namespace std;
struct cmp {
	bool operator() (const char*a, const char* b)const {
		return strcmp(a,b)<0;
	}
};
set<char*,cmp> output;
char state[105];
int solution[4];
int on[2];
int off[2];
	int N,C;
void isOk() {
	char * str = new char[105];
	strcpy(str,state);
	for(int i=0; i<N; i++) {
		if(solution[0]%2 == 1)
			str[i] = str[i]=='1'?'0':'1';
		if(solution[1]%2==1 && (i+1)%2==1)
			str[i] = str[i]=='1'?'0':'1';
		if(solution[2]%2==1 && i%2==1)
			str[i] = str[i]=='1'?'0':'1';
		if(solution[3]%2==1 && (i+1)%3==1)
			str[i] = str[i]=='1'?'0':'1';

	}
	bool flag = true;
	for(int i=0; i<2; i++) {
		if(on[i]!=-1 && str[on[i]-1]!='1') {
			flag = false;
			break;
		}
		if(off[i]!=-1 && str[off[i]-1]!='0') {
			flag = false;
			break;
		}
		str[N] = '\0';

		if(flag) {
			output.insert(str);
		}
		else
            delete [] str;
	}

}

bool prune() {
	int sum = 0;
	for(int i=0; i<4; i++)
		sum += solution[i];
	if(sum>C)
		return true;
	else
		return false;
}
void dfs(int depth) {
	int sum = 0;
	for(int i=0; i<4;i++)
	sum += solution[i];
	if(sum == C)
        isOk();
	if(depth>3)
		return;

	for(int i=0; i<=C; i++) {
		solution[depth] = i;
		if(!prune())
			dfs(depth+1);
	}
	solution[depth] = 0;
	return;
}
int main () {
	memset(state,'1',sizeof(state));
	memset(solution,0,sizeof(solution));
	cin >> N >> C;
	int t;
	cin >> on[0];
	if(on[0]==-1)
		on[1] = -1;
	else {
		cin >> on[1];
		if(on[1]!=-1)
			cin >> t;
	}

	cin >> off[0];
	if(off[0]==-1)
		off[1] = -1;
	else {
		cin >> off[1];
		if(off[1]!=-1)
			cin >> t;
	}

	dfs(0);
	set<char*,cmp>::iterator it;
	for(it = output.begin(); it!=output.end(); it++)
	cout << *it <<endl;
}

