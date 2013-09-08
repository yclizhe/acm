#include <iostream>
using namespace std;
struct Foo {
	Foo() {}
	Foo(int) {}
	void fun() {}
};
int main() {
	int y[2] = {1};
	cout << y[0] << endl;
	cout << y[1] << endl;
	Foo a(10);
	a.fun();
	Foo b;
	b.fun();
	
}
