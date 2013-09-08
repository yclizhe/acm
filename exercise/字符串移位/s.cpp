#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* str, int s, int e) {
	while(s<e) {
		str[s] = str[s]^str[e];
		str[e] = str[s]^str[e];
		str[s] = str[s]^str[e];
		++s;
		--e;
	}
}

int main () {
	char str[1000];
	cin >> str;
	int x;
	cin >> x;
	int len =  strlen(str);
	if(x==len)
		cout << str << endl;
	else { 
		x = x % len;
		reverse(str,0,len-x-1);
		reverse(str,len-x,len-1);
		reverse(str,0,len-1);
		cout << str << endl;
	}
}
