#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
        // ignore leading blanks
        while (i != s.size() && isspace(s[i]))
        {
            ++i;
        }
        // now i is at the first character of the word

        // we will find end of next word        
        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
        {
            ++j;
        }

        // now, we find the end of the word
        if (i != j)     // if we meet the end of string
        {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

int main()
{
    // string s;
    // while (getline(cin, s))
    // {
    //     vector<string> v = split(s);
    //     for (vector<string>::size_type i = 0; i != v.size(); ++i)
    //     {
    //         cout << v[i] << endl;
    //     }
    // }
    
    // return 0;

    // test bultin method
    string s;
    while (cin >> s)
    {
        cout << s << endl;
    }
    
}