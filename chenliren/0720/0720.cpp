#include <map>
#include <cstring>
#include <iostream>
using namespace std;
char str[1000];
int main () {
	while(cin >> str) {
		int n = strlen(str);
		int *l =  new int[n];
		map<int,int> fi;
		map<int,int> se;
		memset(l,0,4*n);
		int diff = 0;
		for(int i=0; i<n; i++) {
			if(str[i] == '0')
				diff--;
			else 
				diff++;
			l[i] = diff;
			if(fi.find(diff)==fi.end())
				fi[diff] = i;
			se[diff] = i;
		}
		fi[0] = -1;
		map<int,int>:: iterator it;
		int max = 0;
		int x,y;
		for(it=fi.begin(); it!=fi.end(); it++) {
			if(max < (se[it->first] - it->second)) {
				x = it->second;
				y = se[it->first];
				max = y-x;
			}
		}
		for(int i=x+1; i<=y; i++)
			cout << str[i];
		cout << endl;
	}	
}
