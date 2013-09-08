#include <iostream>
using namespace std;
int a[10000];
int c[10005] = {0};
int bruteforce(int a[], int n) {
	int count = 0;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				count++;
	return count;
}

int lowbit(int i) {
	return i&(-i);
}

int sum(int n) {
	int s = 0;
	while(n>0) {
		s += c[n];
		n = n - lowbit(n);
	}
	return s;
}
void change(int i, int num, int MAX = 10000) {
	while(i<=MAX) {
		c[i] += num;
		i = i + lowbit(i);
	}
}
int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
    int re = 0;
	for(int i=0; i<n; i++) {
		change(a[i],1);
		re += i+1-sum(a[i]);
    }
	cout << "BruteForce:" << bruteforce(a,n) << endl;
	cout << "TreeArray:" << re<< endl;
}

