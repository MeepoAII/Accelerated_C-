#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::vector;
using std::string;
using namespace std;

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
    vector<string> ret;
    string::size_type maxlen = width(v);

    // write the top border
    string border = string(maxlen + 4, '*');
    ret.push_back(border);

    // write each line
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') +  " *");
    }

    // write the bottom border
    ret.push_back(border);
    
    return ret;
}

int main()
{
    vector<string> test = {"bitcoin", "filecoin", "sfil"};
    vector<string> res = frame(test);
    for (auto x : res) cout << x << endl;

    return 0;
}