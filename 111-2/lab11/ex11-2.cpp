#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool rec(string ss, map<string, int> dic) {
}

int main(int argc, char *argv[]) {
    map<string, int> dictionary;
    ifstream in(argv[1]);
    string ss;
    int amo;
    while (in >> ss >> amo) {
        dictionary.insert(pair<string, int>(ss, amo));
    }
    string testcase = argv[2];
    if (rec(testcase, dictionary)) {
        for (auto p = dictionary.begin(); p != dictionary.end(); p++) {
        }
    }
}
