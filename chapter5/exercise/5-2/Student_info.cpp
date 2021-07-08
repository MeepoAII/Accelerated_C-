#include "Student_info.h"

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}

void readFromFile(string filePath, Student_info& s)
{
    ifstream infile;
    infile.open(filePath);
    // fixed number of students
    for (int i = 0; i < 2; ++i)
    {
        string line;
        getline(infile, line);
        s.name = line;
        cout << s.name;
        getline(infile, line);
        stringstream ss(line);
        ss >> s.midterm >> s.final;
        getline(infile, line);
        stringstream sd(line);
        double x;
        while (sd >> x)
        {
            s.homework.push_back(x);
        }
        
    }

}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        hw.clear();

        double x;
        while (in >> x)
        {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}