#include <iostream>
#include <cstring>
using namespace std;

#define Min(a,b) (a)>(b)?(b):(a)
#define Max(a,b) (a)>(b)?(a):(b)
int main() {
	int cash, n;
	while(cin >> cash >> n) {
		if( n==0){
			cout << 0 << endl;
			continue;
		}
		int* D = new int[10000];
		int* m = new int[cash+1];
		memset(m,0,4*(cash+1));
		int count = 0;
		for(int i=0; i<n; i++){
			int tN, tD;
			cin >> tN >> tD;
			if(tN==0)
				continue;
			for(int k=1;k==k; k=k*2){
				if(tN-k*4+1<=0) {
					D[count++] = tD * k;
					D[count++] = tD * (tN-k*2+1);
					break;
				}
				D[count++] = tD*k;
			}
		}

		for(int i=0; i<count; i++)
			for(int j=cash; j>=D[i]; j--)
				m[j] = Max(m[j], m[j-D[i]]+D[i]);

		cout << m[cash] << endl;
		delete D;
		delete m;
	}
	return 0;

}
