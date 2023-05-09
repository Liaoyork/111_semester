#include <fstream>
#include <iostream>

using namespace std;
int main() {
    int number;
    int sum = 0;
    ifstream infile("file.txt");
    while (infile >> number) {
        sum += number;
    }
    cout << sum;
    return 0;
}