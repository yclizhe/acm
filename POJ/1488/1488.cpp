#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int main () {
	char  str[100];
	stack<char> st;
	while(cin.getline(str,100)) { 
		for(int i=0; i<strlen(str); i++) {
			if(str[i] == '\"' && st.empty()) {
				cout << "``";
				st.push('\"');
			}
			else if(str[i] == '\"' && !st.empty()) {
				cout << "''";
				st.pop();
			}
			else 
				cout << str[i];
		}
		cout << endl;
	}
}
