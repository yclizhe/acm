#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char m[105][6];
int dif(char* str1, char* str2) {
	int re = 0;
	int hash[5] = {0};
	for(int i=0; i<5; i++) {
		int t = 0;
		for(int k=0; k<5; k++) {
			if(str1[i] == str2[k])
				break;
			if(hash[str2[k]-'A']==0)
				t++;
		}
		re += t;
		hash[str1[i]-'A'] = 1;
	}
	return re;
}
int sum(char *str, int n) {
	int s = 0;
	for(int i=0; i<n; i++) 
		s += dif(str, m[i]);
	
	return s;
}
int main() {
	int n;
	while(cin >>n) {
		if(n==0)
			break;
		for(int i=0; i<n; i++)
			cin >> m[i];
		char str[6] = "ABCDE";
		char re[6] = "ABCDE";
		int min = sum(str,n);
		while(next_permutation(str,str+5)) {
			int s = sum(str,n);
			if(s < min) {
				min = s;
				strcpy(re,str);
			}
		}
		cout << re << " is the median ranking with value " << min << "." << endl;
	}
	
}
