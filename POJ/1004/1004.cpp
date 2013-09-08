#include "iostream"
#include "iomanip"
using namespace std;
int main() {
	int n = 12;
	float sum = 0;
	float f;
	while(n-- && cin >> f) 
		sum +=f;
	sum = (float) sum / 12;
	cout << "$" << fixed << setprecision(2) << sum  << endl;
	
}
