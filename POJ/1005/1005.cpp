#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.1415926
int main() {
	int n;
	cin >> n;
	int count = 0;
	while(n--) {
		count++;
		float x,y;
		cin >> x >> y;
		float dist = sqrt(x*x + y*y);
		float current = 0.0;
		int year = 0;
		while(current < dist){
			current = sqrt((float)100/PI+current*current);
			year++;
		}
		cout << "Property " << count << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
}
