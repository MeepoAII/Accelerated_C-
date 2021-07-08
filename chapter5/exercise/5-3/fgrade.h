#ifndef GUARD_FGRADE_H
#define GUARD_FGRADE_H

#include "Student_info.h"
#include "grade.h"

#include <vector>
#include <list>
using std::vector;
using std::list;

bool fgrade(const Student_info& s);
vector<Student_info> extract_fails(vector<Student_info>& students);
list<Student_info> extract_fails(list<Student_info>& students);

#endif