#include "iostream"
using namespace std;
int main() {
	float a;
	while(cin >> a) {
		if(a==0)
			break;
		float sum = 0;
		int count = 0;
		while(sum < a) 
			sum += (float) 1/(++count +1);
		cout << count << " card(s)" << endl;
			
	}
}
