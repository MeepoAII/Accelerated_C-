#include <iostream>
#include <iomanip>
#include "getStreamWidth.h"
using namespace std;

int main()
{
    for (int i = 1; i < 100; ++i)
    {
        cout << "the width is " << getStreamWidth(i) << endl;
        cout << setw(getStreamWidth(i)) << i << " " << i*i << endl;
    }

    return 0;
}