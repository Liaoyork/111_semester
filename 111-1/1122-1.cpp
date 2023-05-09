#include <iostream>
using namespace std;
#define demo1

#ifdef demo1
typedef struct stu_info stu_info;
struct stu_info {
    int stu_id;
    int qu_1;
    int qu_2;
    int qu_3;
};
int main() {
    stu_info s[40];
}
#endif

#ifdef demo2
int main() {
    int len;
    int i, j, key, a[100] = {0};
    cin >> len;
    for (i = 0; i < len; i++) {
        cin >> a[i];
    }
    for (i = 1; i < len; ++i) {
        key = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
#endif

#ifdef demo4
int main() {
    const int MAX = 5;
    int a[MAX] = {0};
    int b;
    int i = 0;
    int l = 0;
    while (1) {
        if (i == MAX) break;
        cout << "�п�J�@�ӼƦr: ";
        cin >> b;
        if (b <= 0)
            continue;

        else {
            a[i] = b;
            l++;
        }
        i++;
    }
    for (i = 0; i < l; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
#endif

#ifdef demo5
int main() {
    int i = 0, j = 0, m = 0, key;
    int a[8] = {1, 4, 7, 7, 7, 4, 3, 3}, b[8] = {0};
    for (i = 1; i < 8; ++i) {
        key = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (i = 0; i < 8; i++) {
        if (b[m] != a[i]) {
            m++;
            b[m] = a[i];
        }
    }
    for (i = 1; i < m + 1; i++) {
        cout << b[i] << " ";
    }
}
#endif
