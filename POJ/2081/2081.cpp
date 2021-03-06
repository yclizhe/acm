#include <iostream>
#include <cstring>
using namespace std;

int bitmap[300000];

#define MASK 0x1F
#define SHIFT 5

void set(int x) {
	bitmap[x>>SHIFT] |= 1 << (x&MASK);
}

bool test(int x) {
	return bitmap[x>>SHIFT] & 1<<(x&MASK);
}


int main() {
	int k;
	while(cin >> k) {
		memset(bitmap,0,sizeof(bitmap));
		if(k==-1)
			break;
		int a = 0;
		set(a);
		for(int i=1; i<=k; i++) {
			int temp = a-i;
			if( temp<0)
				a = a+i;
			else if(test(temp))
				a = a+i;
			else
				a = a-i;
			set(a);
		}
		cout << a << endl;
	}
}
