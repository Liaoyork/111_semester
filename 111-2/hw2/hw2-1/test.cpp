#include <iostream>

using namespace std;

class abc {
   private:
    int a;
    int b;

   public:
    abc() {
        a = 0;
        b = 0;
    }
    abc(int m, int n) {
        a = m;
        b = n;
    }
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};

int main() {
    abc *p;
    abc *data = new abc(3, 5);
    p = data;
    cout << p->getA() << " " << p->getB() << endl;
}