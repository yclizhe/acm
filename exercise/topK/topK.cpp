#include <iostream>
#include <cstring>
#include <set>
using namespace std;
struct entry {
	char key[10];
	int count;
//	bool operator < (const entry b) const{
//		return count < b.count;
//	}
	entry(char * str, int c) {
		strcpy(key,str);
		count = c;
	}
};
struct cmp {
	bool operator () (const entry a, const entry b) const {
		return a.count < b.count;
	} 
};
int main() {
	int n;
	cin >> n;
	set<entry,cmp> s;
	while(n--) {
		char *str = new char[10];
		int c;
		cin >> str >> c;
		entry en(str,c); 
		if(s.size()<3)
			s.insert(en);
		else {
			set<entry>::iterator it = s.begin();
			if(en.count > it->count) {
				s.erase(it);
				s.insert(en);
			}
		}
	}
	set<entry>::iterator it;
	for(it = s.begin(); it!=s.end(); it++)
		cout << it->key << " " << it->count << endl;
}
