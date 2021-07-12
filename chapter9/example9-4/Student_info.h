#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H
#include <vector>
#include <string>
#include <iostream>
class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    bool valid() const { return !homework.empty(); }
    double grade() const;
    std::istream& read(std::istream&);
    std::string name() const { return n; }
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

#endif