#include <iostream>
#include <cstring>
#include <map>
using namespace std;
using namespace __gnu_cxx;
typedef map<char*,char*>::iterator MapIT;
struct MapCmp {
	bool operator() (const char* c1, const char* c2) const {
		return strcmp(c1,c2)<0;
	}
};
int main () {
	char l[25];
	map<char*,char*,MapCmp> m;
	while(cin.getline(l,25)) {
		if(strlen(l)==0)
			break;
		char f[11];
		char e[11];
		int i;
		for(i=0; i<strlen(l); i++)
			if(l[i]!=' ')
				e[i] = l[i];
			else {
				e[i] = '\0';
				break;
			}
		int k=0;
		for(int j=i+1; j<=strlen(l); j++) 
			f[k++] = l[j];
		char * tf = new char[11];
		char * te = new char[11];
		strcpy(tf,f);
		strcpy(te,e);
		m.insert(pair<char*,char*>(tf,te));	
	}
	

	char word[11];
	while(cin >> word) {
		MapIT it;
		it = m.find(word);
		if(it==m.end())
			cout << "eh" << endl;
		else 
			cout << it->second << endl;
	}
}
