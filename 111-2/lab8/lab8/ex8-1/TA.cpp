
#include "TA.h"

#include <iostream>

#include "Course.h"
using namespace std;

TA::TA(string id, string name, string email, string password, string degree, int tuition, int salary) : Personnel(id, name, email, password), Student(id, name, email, password, degree, tuition), Teacher(id, name, email, password, salary) {
    ;
}
void TA::printInfo() {
    Personnel::printInfo();
    cout << "salary: " << salary << endl;

    cout << "Taught Courses: " << endl;
    for (int i = 0; i < (int)taughtCourses.size(); i++) {
        cout << "\"";
        cout << taughtCourses[i]->getName();
        cout << "\"";
        cout << " ";
    }

    cout << "Attend Courses: " << endl;
    for (int i = 0; i < (int)attendedCourses.size(); i++) {
        cout << "\"";
        cout << attendedCourses[i]->getName();
        cout << "\"";
        cout << " ";
    }
}
