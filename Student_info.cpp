#include "Student_info.h"

bool compare(Student_info& a, Student_info& b) {
        return a.name() < b.name();
}

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(std::istream& is) { read(is); }
