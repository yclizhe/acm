#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int main () {
	int x;
	int count = 0;
	while(cin >> x) {
		if (x==0)
			break;
		a[count++] = x;
	}
	qsort(a,count,4,cmp);
	for(int i=0; i<count; i++) 
		cout << a[i] << " ";
	cout << endl;
}
