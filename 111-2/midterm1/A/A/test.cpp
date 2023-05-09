#include <iostream>

using namespace std;

class A {
   private:
    int a;
    int b;
    int *c;
    friend ostream &operator<<(ostream &, A &);

   public:
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
    void Createc() {
        c = new int[3];
        c[0] = 1;
        c[1] = 2;
        c[2] = 3;
    }
    A() {
        a = 5;
        b = 6;
        Createc();
    }
    void changeA() {
        a = 15;
    }
    A operator+(A &o1) {
        A temp;
        temp.a = this->a + o1.a;
        temp.b = this->b + o1.b;
        for (int i = 0; i < 3; i++) {
            temp.c[i] = this->c[i] + o1.c[i];
        }
        return temp;
    }
};
ostream &operator<<(ostream &out, A &o1) {
    cout << "a = " << o1.a << endl;
    cout << "b = " << o1.b << endl;
    for (int i = 0; i < 3; i++) {
        cout << o1.c[i] << " ";
    }
    cout << endl;
}

int main() {
    A ob1;
    cout << "ob1: " << endl;
    cout << ob1;
    ob1 = ob1 + ob1;
    cout << "new ob1: " << endl;
    cout << ob1;
    ob1.changeA();
    cout << "new ob1: " << endl;
    cout << ob1;
    A ob2 = ob1;
    cout << "new ob2: " << endl;
    cout << ob2;

    // cout << k;
}