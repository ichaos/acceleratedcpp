#include <iostream>
#include <string>
#include <vector>

class Student_info {
        std::string n;
        std::vector<double> homework;
        double midterm, final;
 public:
        Student_info();
        Student_info(std::istream&);
        double grade() const;
        std::istream& read(std::istream&);
        std::string name() const { return n; };
};

bool compare(Student_info&, Student_info&);
