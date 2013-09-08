#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
char words[105][8];
char shuffle[105][8];

struct cmp {
	bool operator()(const char* str1, const char* str2) const {
		return strcmp(str1, str2) < 0;
	}
};
set<char*,cmp> ans;

int main(){
	char str[8];
	int count = 0;
	while(cin >> str) {
		if(str[0] == 'X')
			break;
		strcpy(words[count],str);
		sort(str, str+strlen(str));
		strcpy(shuffle[count],str);
		count++;
	}
	while(cin >> str) {
		if(str[0] == 'X')
			break;
		sort(str, str+strlen(str));
		ans.clear();
		for(int i=0; i<count; i++)
			if(strcmp(shuffle[i],str)==0) {
				char* tmp = new char[8];
				strcpy(tmp, words[i]);
				ans.insert(tmp);
			}
		if(ans.size()==0)
			cout << "NOT A VALID WORD" << endl;
		else {
			set<char*, cmp>::iterator it;
			for(it=ans.begin(); it!=ans.end(); it++)
				cout << *it << endl;
		}
		cout << "******" << endl;
	}
	
}
