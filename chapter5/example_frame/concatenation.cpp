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

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    // copy the top picture
    vector<string> ret = top;
    
    // copy entire bottom picture
    // for (vector<string>::const_iterator it = bottom.begin();
    //     it != bottom.end(); ++it)
    // {
    //     ret.push_back(*it);
    // }

    // we can use insert instead for loop
    ret.insert(ret.end(), bottom.begin(),bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size())
    {
        string s;

        if(i != left.size())
        {
            s = left[i++];
        }
        
        s += string(width1 - s.size(), ' ');

        if (j != right.size())
        {
            s += right[j++];
        }

        ret.push_back(s);
    }
    return ret;
    
}

int main()
{
    vector<string> s1{"bitcoin", "fil", "xmr", "ethereum", "dodo"};
    vector<string> s2{"trx", "uni", "foc", "bnb", "ht", "gt"};
    vector<string> res = hcat(s1, s2);
    for (auto x : res) std::cout << x << std::endl;
    return 0;
}
