#include <iostream>
#include <set>
#include <cstring>
#include <map>
using namespace std;
struct cmp {
	bool operator() (const char* a, const char* b) const {
		return strcmp(a,b)<0;

	}
};

char map1[100][50];
map<char*, int, cmp> map2;
int path[100];
int age[100];

void merge(int f, int c, int fage) {
	path[c] = f;
	age[c] = fage;
}
int find(int x) {
	if(path[x] == x)
		return x;
	int re = find(path[x]);
	age[x] += age[path[x]];
	path[x] = re;
	return re;
}

struct entry {
	char name[50];
	int old;
	entry(char *n, int o) {
		strcpy(name,n);
		old = o;
	}
	friend bool operator < (const entry e1, const entry e2){
		if(e1.old!=e2.old)
			return e1.old < e2.old;
		else
			return strcmp(e1.name,e2.name)<0;
	}
};
int main () {
	int n;
	cin >>n;
	int x;
	for(x=1; x<=n; x++) {
		memset(map1,0,sizeof(map1));
		memset(path,-1,sizeof(path));
		memset(age,100,sizeof(age));
		map2.clear();
		path[0] = 0;
		age[0] = 0;
		strcpy(map1[0],"Ted");
		map2.insert(pair<char*,int>("Ted",0));
		int num;
		cin >> num;
		int count = 1;
		for(int i=1; i<=num; i++) {
			int fage;
			int idf, idc;
			char* fname = new char[50];
			char* cname = new char[50];
			cin >> fname >> cname >> fage;
			if(map2.find(fname)!=map2.end()) {
				idf = map2.find(fname)->second;
			}
			else {
				strcpy(map1[count],fname);
				map2.insert(pair<char*,int>(fname,count));
				idf = count++;
			}
			if(map2.find(cname)!=map2.end()) {
				idc = map2.find(cname)->second;
			}
			else {
				strcpy(map1[count],cname);
				map2.insert(pair<char*,int>(cname,count));
				idc = count++;
			}
			age[idc] = fage;
			path[idc] = idf;

		}

		set<entry> s;
		for(int i=1; i<=num; i++) {
			find(i);
			entry en(map1[i],age[i]);
			s.insert(en);

		}
		cout << "DATASET " << x << endl;
		set<entry>::iterator it;
		for(it=s.begin(); it!=s.end(); it++)
			cout << it->name << " "  << 100-it->old << endl;

	}
}

