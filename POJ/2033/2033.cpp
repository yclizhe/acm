#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int decode(char a, char b) {
	int x = 10*(a-'0') + b-'0';
	if(x>=10 && x<=26)
		return 1;
	else
		return 0;
}

char str[5000];
int main() {
	while(1) {
		scanf("%s",str);
		if(strcmp(str,"0") == 0)
			break;
		int f0,f1,f2;
		f0 = 1;
		if(str[1] =='\0') {
			cout << 1 << endl;
			continue;
		}
		if(str[1] == '0')
			f1 = 1;
		else
			f1 = 1 + decode(str[0],str[1]);
		f2 = f1;
		char * temp = str+2;
		while(*temp) {
			if(*temp == '0')
				f2 = f0;
			else
				f2 = f1+f0*decode(*(temp-1), *temp);
			f0 = f1;
			f1 = f2;
			temp++;
		}
		cout << f2 << endl;
		
	}
}
