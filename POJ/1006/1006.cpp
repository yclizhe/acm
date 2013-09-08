#include <iostream>
using namespace std;
#define A (a-D)%23
#define B (b-D)%28
#define C (c-D)%33
int main(){
	int a,b,c,d;
	int D;
	int count = 0;
	while(cin >> a >> b >> c >> d) {
		if(a < 0)
			break;
		D = d + 1;
		while(A || B || C)
			D++;
		cout << "Case " << ++count << ": the next triple peak occurs in " << D-d << " days." << endl;

	}
}
