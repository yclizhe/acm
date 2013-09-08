#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
struct str_hash {
    size_t operator () (string str) const{
        return __stl_hash_string(str.c_str());
    }
};
typedef hash_map<string,string,str_hash>::iterator MapIT;
struct MapCmp {
	bool operator() (const char* c1, const char* c2) const {
		return strcmp(c1,c2)<0;
	}
};


int main () {
	char l[25];
	hash_map<string,string,str_hash> m;
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
		string tf(f);
		string te(e);
		m.insert(pair<string,string>(tf,te));
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

