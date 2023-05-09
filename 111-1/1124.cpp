#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define demo3

#ifdef demo1
int main() {
    int temp[6];
    string str;
    cin >> str;
    for (int i = 0; i < 6; i++) {
        if (str[i + 1] - str[i] > 0)
            temp[i] = str[i + 1] - str[i];
        else
            temp[i] = str[i] - str[i + 1];
    }
    for (int i = 0; i < 6; i++) {
        cout << temp[i];
    }
    return 0;
}
#endif

#ifdef demo2
int main() {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1)
                cout << arr[j][i];
            else
                cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif

#ifdef demo3
int main() {
}
#endif
