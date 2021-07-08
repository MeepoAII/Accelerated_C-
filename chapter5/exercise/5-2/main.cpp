#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "fgrade.h"
#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   // 记录那个最长的名字，方便在报表中空格

    // read and store all the students data.
    while (read(cin, record))
    {
        // find length if longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // extract failing students;
    vector<Student_info> fails = extract_fails(students);


    // write the names and grades
    for (vector<Student_info>::const_iterator iter = students.begin();
        iter != students.end(); ++iter)
    {
        // write the name, paddedd on the right to maxlen + 1 characters
        cout << (*iter).name
            << string(maxlen + 1 - (*iter).name.size(), ' ');

        // compute and write the grade
        try
        {
            double final_grade = grade((*iter));
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch(domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}