#include <iostream>
#include <string>
using namespace std;

typedef string::size_type str_sz;

int main()
{
    string tmp;
    str_sz min = 1000;
    str_sz max = 0;
    cout << "Please input words, end with end-of-file: ";
    while (cin >> tmp)
    {
        if (tmp.size() < min) min = tmp.size();
        if (tmp.size() > max) max = tmp.size();
    }
    cout << "min and max: " << min << " " << max << endl;
}