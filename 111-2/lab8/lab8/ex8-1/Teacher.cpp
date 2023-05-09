#include "Teacher.h"

#include <iostream>

#include "Course.h"

using namespace std;

Teacher::Teacher(string id, string name, string email, string password, int salary) : Personnel(id, name, email, password) {
    this->salary = salary;
}

void Teacher::printInfo() {
    cout << "Teacher: " << endl;
    Personnel::printInfo();
    cout << "salary: " << salary << endl;
    for (int i = 0; i < (int)taughtCourses.size(); i++) {
        cout << "\"";
        cout << taughtCourses[i]->getName();
        cout << "\"";
        cout << " ";
    }
}
void Teacher::addTaughtCourse(Course* course) {
    taughtCourses.push_back(course);
}
