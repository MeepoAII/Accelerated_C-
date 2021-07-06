#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        maxlen = std::max(v[i].size(), maxlen);
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{

}