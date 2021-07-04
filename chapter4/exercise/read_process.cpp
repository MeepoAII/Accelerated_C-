#include "read_process.h"

using std::istream;
using std::vector;
using std::string;

istream& read_process(istream& is, vector<string>& save)
{
    typedef vector<string>::size_type vec_sz;
    // print the number of words, and how many time each word occured
    if (is)
    {
        save.clear();
        string tmp;
        vec_sz cnt = 0;
        while (is >> tmp)
        {
            ++cnt;
            vec_sz appear = 1;
            for (vec_sz i = 0; i < save.size(); ++i)
            {
                if (tmp == save[i]) ++appear;
            }
            std::cout << tmp << " : " << appear << std::endl;
            save.push_back(tmp);
        }
        std::cout << "The number of string you input is: " << cnt << std::endl;
    }
    return is;
}