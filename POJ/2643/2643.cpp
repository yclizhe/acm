#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;

struct str_cmp {
	bool operator() (const char *str1, const char *str2) const {
		return strcmp(str1,str2)<0;
	}
};

map<char*,char*,str_cmp> ca;
map<char*,int,str_cmp> count;

void updateone(char * str) {
	map<char*,int,str_cmp>::iterator it;
	it = count.find(str);
	if(it == count.end())
		count.insert(pair<char*,int>(str,1));
	else {
		count[str] += 1;
	}	
}

int main () {
	int n,m;
	cin >> n;
	getchar();
	while(n--) {
		char* name = new char[100];
		char* party = new char[100];
		cin.getline(name,100);
		cin.getline(party,100);
		ca.insert(pair<char*,char*>(name,party));
	}
	cin >> m;
	getchar();
	while(m--) {
		char * name = new char[100];
		cin.getline(name,100);
		updateone(name);
	}
	map<char*,int,str_cmp>::iterator it;
	int max = 0;
	char * name;
	bool status = false;
	for(it=count.begin(); it!=count.end(); it++) {
		int va = it->second;
		if(va > max) {
			max = va;
			name = it->first;
			status = true;
		}
		else if(va == max) 
			status = false;
	} 
	if(status)
		cout << ca[name] << endl;
	else
		cout << "tie" << endl;

	return 0;

}
