#include <string>
#include <iostream>
#include <vector>
class Student_info
{
public:
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};
