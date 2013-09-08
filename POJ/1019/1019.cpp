#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		int p;
		cin >> p;
		int sum = 0;
		int y = 0;
		for(int i=1; i<=2147483647; i++) {
			sum += i;
			if(sum > p){
				y = i;
				break;
			}
		}
		int x = p -sum + y;
		if(x == 0)
			x = y-1;
		cout << x << endl;
	}
}
