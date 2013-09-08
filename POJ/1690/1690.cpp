#include <iostream>
#include <cstring>
using namespace std;
void trim(char* str) {
	int n = strlen(str);
	int count = 0;
	char tmp[256];
	for(int i=0; i<n; i++) 
		if(str[i]!=' ')
			tmp[count++] = str[i];
	tmp[count] = '\0';
	strcpy(str,tmp);
}
void f(char *str) {
		int n = strlen(str);
		bool flag = false;
		for(int i=0; i<n; i++) {
			if(str[i] == '(') {
				if(i==0) {
					str[i] = ' ';
					str[n-1] = ' ';
				}
				if(str[i-1] != '-' || str[i+2]==')') {
					str[i] = ' ';
					flag = true;
				}	
			}
			else if(str[i]==')' && flag) {
				str[i] = ' ';
				flag = false;
			}
		}
		trim(str);
}
int main () {
	char str[256];
	int N;
	cin >> N;
	cin.get();
	while(N--) {
		cin.getline(str,256);
		trim(str);
		char tmp[256];
		while(true) {
			strcpy(tmp,str);
			f(str);
			if(strcmp(tmp,str)==0)
				break;
		}
		cout << str << endl;
	}
	return 0;
}
