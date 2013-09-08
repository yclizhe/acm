#include <iostream>
#include <cstring>
using namespace std;
#define id(a) (a-1)/2
int *counts = new int[200];
int main() {
	int n;
	cin >> n;
	while(n--) {
		memset(counts, 0, sizeof(counts));
		for(int i=0; i<200; i++)
			counts[i] = 0;
		int count;
		cin >> count;
		while(count--) {
			int a,b;
			cin >> a >> b;
			int ida, idb;
			ida = id(a);
			idb = id(b);
			if(ida == idb)
				counts[ida]++;
			else if(ida < idb){
				for(int i=ida; i<=idb; i++)
					counts[i]++;
			}
			else {
				for(int i=idb; i<=ida; i++)
					counts[i]++;
			}
		}
		int max = 0;
		for(int i=0; i<200; i++) {
			if(counts[i] > max)
				max = counts[i];
		}
		cout << max * 10 << endl;
	}
	return 0;
}
