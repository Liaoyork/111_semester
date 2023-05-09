#include <iostream>

using namespace std;

int main () {
    int c = 1;
    int d = 5;
    int *a = &c;
    int *b = &d; 
    void * p = (void*)a;
    void * q = (void*)b;
    if (*(int*)p > *(int*)q) {
        cout << *(int*)p << endl;
    } else {
        cout << *(int*)q << endl;
    }
}
