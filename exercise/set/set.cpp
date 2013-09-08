#include <iostream>
#include <set>
using namespace std;
typedef set<int>::iterator it;
int main() {
	set<int> s;
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		s.insert(a);
	}
	it i1;
	set<int>:: reverse_iterator i2;
	i1 = s.begin();
	i2 = s.rbegin();
	cout << *i1 << "  " << *i2 << endl;

}
