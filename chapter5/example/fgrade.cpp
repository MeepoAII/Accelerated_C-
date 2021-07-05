#include "Student_info.h"
#include "grade.h"

#include <vector>
using std::vector;


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            students.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return fail;
    
}