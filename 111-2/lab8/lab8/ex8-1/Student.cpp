#include "Student.h"

#include <fstream>
#include <iostream>

#include "Course.h"

using namespace std;

Student::Student(string id, string name, string email, string password, string degree, int tuition) : Personnel(id, name, email, password) {
    this->degree = degree;
    this->tuition = tuition;
}
void Student::printInfo() {
    Personnel::printInfo();
    cout << "Degree: " << degree << "\t"
         << "Tuition: " << tuition << endl;

    for (int i = 0; i < (int)attendedCourses.size(); i++) {
        cout << "\"";
        cout << attendedCourses[i]->getName();
        cout << "\"";
        cout << " ";
    }
}
void Student::addAttendCourse(Course* course) {
    attendedCourses.push_back(course);
}
