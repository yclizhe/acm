#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
using namespace std;
char a[100];
char b[100];
stack<char> OPST;
stack<int> VAST;

int getPri(char c) {
	if(c == '(' || c == '#')
		return 0;
	else if(c == '+' || c == '-')
		return 1;
	else
		return 2;
}


int operate(int x, int y, char o) {
	if(o == '+')
		return y+x;
	else if(o == '-')
		return y-x;
	else
		return y*x;
}

int getValue(char *a) {
	int n = strlen(a);
	OPST.push('#');
	for(int i=0; i<n; i++) {
		char c = a[i];
		if(c == ' ' || c == '\t')
			continue;
		if(c == '*' || c=='+' || c=='-') {
			if(c == '*')
				OPST.push(c);
			else {
				char pc = OPST.top();
				while( getPri(pc) >= getPri(c) ) {
					OPST.pop();
					int x = VAST.top();
					VAST.pop();
					int y = VAST.top();
					VAST.pop();
					VAST.push(operate(x,y,pc));
					pc = OPST.top();

				}
				OPST.push(c);
			}
		}
		else if(c == '(') {
			OPST.push(c);
		}
		else if(c == ')') {
			char o;
			while( (o=OPST.top()) != '(') {
				OPST.pop();
				int x = VAST.top();
                VAST.pop();
				int y = VAST.top();
				VAST.pop();
				int re = operate(x,y,o);
				VAST.push(re);
			}
			OPST.pop();
		}
		else {
            int t =  c - '0';
			VAST.push(t);
		}
	}

	char o;
	while( (o=OPST.top()) != '#') {
		OPST.pop();
		int x = VAST.top();
		VAST.pop();
		int y = VAST.top();
		VAST.pop();
		int re = operate(x,y,o);
		VAST.push(re);
	}
	return VAST.top();
}

int main() {
	char cN[10];
	cin.getline(cN,9);
	int N = atoi(cN);
	while(N--) {
		while(!OPST.empty())
			OPST.pop();
		while(!VAST.empty())
			VAST.pop();
        cin.getline(a,99);
		cin.getline(b,99);
		int va = getValue(a);
		int vb = getValue(b);
		if(va == vb)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

