#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream in;
    in.open(argv[1]);
    ofstream out;
    out.open("123.txt");
    char temp;
    vector<char> vec;

    while (in >> temp) {
        vec.push_back(temp);
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        out << vec[i] << " ";
    }

    return 0;
}