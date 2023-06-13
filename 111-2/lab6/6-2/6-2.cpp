#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
int main (){
    ifstream input("1.dat", ios::binary);
    int in;
    if (!input) {
    cout << "1.dat is not opened";
        return -1;
    }
    //cout << sizeof(int) << endl;
    vector<int> a;
    while (!input.eof()) {
        input.read((char *)&in, sizeof(int));
        if (input.eof()) break;
        a.push_back(in);
    }
    /*
    for (auto p : a){
        cout << p << " ";
    }
    */
    
}
