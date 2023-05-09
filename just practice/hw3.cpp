#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ifstream in;
ofstream out;

string *addEntry(string *dynamicArray, int &size, string newEntry) {
    string *buf;
    buf = new string[size + 1];

    for (int i = 0; i < size; i++) {
        buf[i] = dynamicArray[i];
    }
    buf[size] = newEntry;
    for (int i = 0; i < size; i++) {
        buf[i] = dynamicArray[i];
    }
    size++;
    delete[] dynamicArray;
    return buf;
}

string *deleteEntry(string *dynamicArray, int &size, string entryToDelete) {
    bool find = false;
    string *buf;
    buf = new string[size];

    int k = 0;
    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == entryToDelete) {
            if (find) {
                buf[k] = dynamicArray[i];
                k++;
            }
            find = true;
        } else {
            buf[k] = dynamicArray[i];
            k++;
        }
    }
    if (!find)
        out << "null" << endl;
    else
        size--;

    delete[] dynamicArray;
    return buf;
}

int main(int argc, char *argv[]) {
    in.open(argv[1]);
    out.open(argv[2]);
    string ss;
    int line;
    in >> ss;
    line = stoi(ss);
    string *ans = new string[line];
    int size = 0;

    for (int i = 0; i < line; i++) {
        in >> ss;
        if (ss == "add") {
            in >> ss;
            ans = addEntry(ans, size, ss);
        } else if (ss == "delete") {
            in >> ss;
            ans = deleteEntry(ans, size, ss);
        }
    }

    out << endl
        << size << endl;
    for (int i = 0; i < size; i++) {
        out << ans[i];
        out << endl;
    }
    return 0;
}