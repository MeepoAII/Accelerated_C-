#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{

    vector<string> names;
    vector<double> grades;
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    while (cin >> name)
    {    
        cout << "Hello, " << name << "!" << endl;
        names.push_back(name);

        // ask for and read the midterm and final grades
        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;
        
        // ask for and read the homework grades
        cout << "Enter all your homework grades, "
                "followed by end-of-file: ";

        vector<double> homework;
        double x;

        // if we use this, program will only get one name! why?
        while (cin >> x)
        {
            homework.push_back(x);
        }

        // for (int i = 0; i < 3; i++)
        // {
        //     cin >> x;
        //     homework.push_back(x);
        // }

        // check that the student entered some homework grades
        typedef vector<double>::size_type vec_sz;
        vec_sz size = homework.size();
        if (size == 0)
        {
            cout << endl << "You must enter your grades. "
                            "Please try again. " << endl;
            return 1;
        }

        // sort the grades;
        sort(homework.begin(), homework.end());

        vec_sz mid = size / 2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
                                : homework[mid];
        
        // compute and write the final grade
        streamsize prec = cout.precision();
        double grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
        grades.push_back(grade);

        cout << "Your final grade is " << setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * median
            << setprecision(prec) << endl;
        


        cin.clear();

    }
    
    typedef vector<string>::size_type vec_sz;
    for (vec_sz i = 0; i < names.size(); ++i)
    {
        cout << names[i] << ": " << grades[i] << endl;
    }
    
    return 0;
}