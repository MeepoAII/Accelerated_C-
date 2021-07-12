#include <iostream>
using namespace std;
int main() {
	int x = 5;

	int* p = &x;
	cout << "x=" << x << endl;
	*p = 6;
	cout << "x=" << x << endl;
	return 0;
}