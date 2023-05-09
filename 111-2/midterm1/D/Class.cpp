// This menu function is for your reference
#include "Class.h"

#include <iostream>
using namespace std;

// static family
vector<string> Teacher::total_vec(0);
vector<Teacher *> Teacher::total_obj_ptr_vec(0);
vector<string> Course::total_vec(0);
vector<Course *> Course::total_obj_ptr_vec(0);
vector<string> Student::total_vec(0);
vector<Student *> Student::total_obj_ptr_vec(0);

// Course
Course::Course() {
    tea_arr = new Teacher *[2];
    stu_arr = new Student *[5];
}
Course::~Course() {
}
Course::Course(string name, Teacher *teacher_ptr) {
    tea_arr = new Teacher *[2];
    this->name = name;
    stu_arr = new Student *[stu_num];
    tea_arr = new Teacher *[teacher_num];
}
void Course::createNewCourse(string name, Teacher *teacher_ptr) {
    Course *cou;
    cou->tea_arr[0] = teacher_ptr;
    cou->stu_num = 0;
    cou->teacher_num = 1;
    cout << "-------------------" << endl;
    cout << teacher_ptr->get_name() << endl;
    cout << "-------------------" << endl;
    total_obj_ptr_vec.push_back(cou);
    total_vec.push_back(name);
}

// Teacher
Teacher::Teacher(string name, string password) : password(password) {
    this->name = name;
    course_arr = new Course *[3];
}

bool Teacher::check_password(string input) const {
    if (input == password) return true;
    return false;
}
Teacher::Teacher() {
    ;
}
Teacher::~Teacher() {
    ;
}

bool Teacher::menu() {
    cout << "----------User Menu----------" << endl;
    cout << "You have " << course_num << " courses." << endl;
    int index = -1;
    for (int i = 0; i < course_num; i++) {
        cout << (i + 1) << ". " << (*(course_arr[i])).name << endl;
    }
    cout << (course_num + 1) << ". Select new course." << endl;
    cout << (course_num + 2) << ". Back to teacher mode." << endl;
    cout << (course_num + 3) << ". Logout." << endl;
    string ch_str = "";
    int ch = 0;
    while (ch_str < "1" || ch_str > to_string(course_num + 3) || ch_str.size() != 1) {
        cout << "Choice: ";
        cin >> ch_str;
    }
    ch = (int)ch_str[0] - 48;
    if (ch == (course_num + 3)) {
        cout << "Back to the Main Menu" << endl
             << endl;
        return false;
    } else if (ch == (course_num + 2)) {
        // if (simulate) {
        //     Back_to_Teacher_mode();
        //     return false;
        // } else {
        //     cout << "You are not available to do this" << endl
        //          << endl;
        //     ;
        // }
    } else if (ch == (course_num + 1)) {
        // select_course();
    } else {
        cout << "----------Course Menu----------" << endl;
        index = ch - 1;
        cout << (*(course_arr[index]));
        cout << "1. Previous page." << endl;
        ch_str = "";
        ch = 0;
        while (ch_str < "1" || ch_str > "1" || ch_str.size() != 1) {
            cout << "Choice: ";
            cin >> ch_str;
        }
        ch = (int)ch_str[0] - 48;
    }
    return true;
}
string Teacher::get_name() const {
    return name;
}

// void Teacher::Simulate_Student_mode() {
// }

void Teacher::createNewTeacher(string name, string password) {
    Teacher *tea = NULL;
    tea = new Teacher(name, password);
    tea->course_num = 0;
    total_obj_ptr_vec.push_back(tea);
    total_vec.push_back(name);
}

// Student
Student::Student() {
    course_arr = new Course *[3];
}

Student::Student(string name, string password) : password(password) {
    this->name = name;
}

void Student::createNewStudent(string name, string password) {
    Student *stu = NULL;
    stu = new Student(name, password);
    stu->course_num = 0;
    total_obj_ptr_vec.push_back(stu);
    total_vec.push_back(name);
}

Student::~Student() {
}

bool Student::menu() {
    cout << "----------User Menu----------" << endl;
    cout << "You have " << course_num << " courses." << endl;
    int index = -1;
    for (int i = 0; i < course_num; i++) {
        cout << (i + 1) << ". " << (*(course_arr[i])).name << endl;
    }
    cout << (course_num + 1) << ". Select new course." << endl;
    cout << (course_num + 2) << ". Back to teacher mode." << endl;
    cout << (course_num + 3) << ". Logout." << endl;
    string ch_str = "";
    int ch = 0;
    while (ch_str < "1" || ch_str > to_string(course_num + 3) || ch_str.size() != 1) {
        cout << "Choice: ";
        cin >> ch_str;
    }
    ch = (int)ch_str[0] - 48;
    if (ch == (course_num + 3)) {
        cout << "Back to the Main Menu" << endl
             << endl;
        return false;
    } else if (ch == (course_num + 2)) {
        if (simulate) {
            Back_to_Teacher_mode();
            return false;
        } else {
            cout << "You are not available to do this" << endl
                 << endl;
            ;
        }
    } else if (ch == (course_num + 1)) {
        select_course();
    } else {
        cout << "----------Course Menu----------" << endl;
        index = ch - 1;
        cout << (*(course_arr[index]));
        cout << "1. Previous page." << endl;
        ch_str = "";
        ch = 0;
        while (ch_str < "1" || ch_str > "1" || ch_str.size() != 1) {
            cout << "Choice: ";
            cin >> ch_str;
        }
        ch = (int)ch_str[0] - 48;
    }
    return true;
}

void Student::select_course() {
    string c_n;
    cout << "course name: ";
    cin >> c_n;
    // cout << Course::total_obj_ptr_vec.size();
    for (int i = 0; i < Course::total_vec.size(); i++) {
        if (Course::total_obj_ptr_vec[i]->name == c_n) {
            // input stu's course

            Course *temp = new Course[course_num];
            for (int j = 0; j < course_num; j++) {
                temp[j] = *course_arr[j];
            }
            delete[] course_arr;
            course_num++;
            course_arr = new Course *[course_num];
            for (int j = 0; j < course_num - 1; j++) {
                *course_arr[j] = temp[j];
            }
            course_arr[course_num]->name = c_n;
            course_arr[course_num]->stu_num++;
            Course::total_obj_ptr_vec.erase(Course::total_obj_ptr_vec.begin() + i);
            Course::total_obj_ptr_vec.push_back(*course_arr);
            Course::total_vec.erase(Course::total_vec.begin() + i);
            Course::total_vec.push_back(name);
            break;
        }
    }
    // input new data to Course

    // erase the old target course
    // for (int i = 0)
}

string Student::get_name() const {
    return name;
}

void Student::Back_to_Teacher_mode() {
    cout << "You are not allow to do this" << endl;
}

bool Student::check_password(string input) const {
    if (input == password) return true;
    return false;
}

ostream &operator<<(ostream &out, Course &c) {
    cout << "this course is " << c.name << endl;
    cout << "teacher: " << c.teacher_num << endl;
    // cout << "student: " << c.stu_arr;
    // for (int i = 1; i < c.stu_num; i++) {
    //     cout << ", " << c.stu_arr;
    // }
    // cout << endl;
    // cout << "homework: " << c.HW_vec[0];
    // for (int i = 1; i < c.HW_vec.size(); i++) {
    //     cout << ", " << c.HW_vec[i];
    // }
    // cout << endl;
    return out;
}