#include <iostream>
#include <cstring>
#include <hash_set>
using namespace std;
using namespace __gnu_cxx;
#define MASK 0x1f
#define SHIFT  0x5
int main() {
	int n,m;
	cin >> n >> m;
	hash_set<int> flag;
	int count = 0;
	while(n--) {
		int x;
		cin >> x;
		flag.insert(x);
		if(flag.size()==m) {
			count++;
			flag.clear();
		}
	}
	cout << ++count << endl;
}
