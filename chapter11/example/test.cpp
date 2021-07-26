#include "Vec.h"
#include <iostream>
using namespace std;
int main() {
	Vec<int> test(1, 1);
	test.push_back(2);
	test.push_back(3);
	// test.push_back(4);
	for (Vec<int>::size_type i = 0; i < test.size(); i++)
		cout << test[i] << endl;
	return 0;
}