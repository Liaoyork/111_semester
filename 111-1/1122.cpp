#include <cstring>
#include <iostream>
#include <string>
#define demo2
using namespace std;
#ifdef demo1
int main() {
    char a[10];
    char c[10];
    cin >> a;
    for (int i = strlen(a) - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}
#endif

#ifdef demo2
int main() {
    char a[1000];
    char b[10];
    int m = 0;
    int temp = -1;
    int count[10] = {0};
    cin >> a;

    for (int i = 0; i < strlen(a); i++) {
        for (int j = i; j < strlen(a); j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                /*
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
                */
            }
        }
    }

    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == a[i + 1]) {
            a[m] = a[i];
            m++;
        }
    }
    int l = -1;
    for (int i = 0; i <= m; i++) {
        if (b[l] != a[i]) {
            l++;
            b[l] = a[i];
        }
    }
    for (int i = 0; i < l; i++) {
        cout << b[i];
    }
}
#endif

#ifdef demo3
int main() {
    char a[100];
    cin >> a;
    for (int i = 0; i < strlen(a); i++) {
        if ((int(a[i]) >= '0' && a[i] <= '9') || a[i] >= 65 && a[i] >= 90)|| (int (a[i])>=97 && int (a[i])<=122)){
                cout << a[i];
            }
    }
    return 0;
}
#endif

#ifdef demo4
#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int *p = &n;  // p is a pointer variable
    cout << "The address of n is " << &n << endl;
    cout << "The value of p is " << *p << endl;
    cout << "The address of p is " << &p << endl;
    cout << "The variable pointed by p is " << p << endl;
}

#endif
