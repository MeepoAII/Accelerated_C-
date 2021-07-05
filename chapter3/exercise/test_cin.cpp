#include <iostream>
using namespace std;

int main()
{
	int a = 0;
    int b = 1;
    while(cin >> a)
    {
        cout << "We are in outside while structure!\n";
        while(cin >> b)
        {
            cout << "We are in inside while structure!\n";
        }
        cin.clear();    // if not clear cin buffer, program will only get one a
    }
}