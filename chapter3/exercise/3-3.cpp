#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string>::size_type vec_sz;

int main()
{
    vector<string> save;
    vector<int> count;
    string tmp;
    cout << "Please input your words, until end-of-file\n";
    while (cin >> tmp)
    {
        save.push_back(tmp);
        count.push_back(1);
    }

    // get cnt for all string
    for (vec_sz i = 0; i < save.size(); i++)
    {
        string first = save[i];
        bool flag = true;
        for (vec_sz j = 0; j < save.size(); j++)
        {
            if (i == j) continue;
            else
            {
                if (first == save[j])
                {
                    ++count[i];
                }
            }
        }

        for (vec_sz j = 0; j < i; j++)
        {
            if (first == save[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            cout << first << ": " << count[i] << endl;
        }
    }

    return 0;
}