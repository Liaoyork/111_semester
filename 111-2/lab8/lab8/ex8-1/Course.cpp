#include "Course.h"

#include <iostream>

#include "Student.h"
#include "TA.h"
#include "Teacher.h"
using namespace std;

Course::Course(string id, string name, Teacher* teacher) {
    this->id = id;
    this->name = name;
    this->teacher = teacher;
}

void Course::addTA(TA* ta) {
    TAs.push_back(ta);
}
void Course::addStudent(Student* student) {
    students.push_back(student);
}

void Course::printInfo() {
    cout << "id: " << id << "\t"
         << "Name: " << name << endl;
    teacher->printInfo();
    for (int i = 0; i < (int)TAs.size(); i++) {
        TAs[i]->printInfo();
        cout << endl;
    }
}

string Course::getName() {
    return name;
}
