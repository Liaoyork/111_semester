#include <iostream>
using namespace std;
int main() {
    int h;
    cout << "Input the height: ";
    cin >> h;
    for (int i = 0; i <= h / 2; i++) {
        for (int j = 0; j <= 2 * h - 1; j++) {
            if (j == h / 2 - i || j == h / 2 + i || j == h / 2 - i + h - 1 || j == h / 2 + i + h - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = h / 2; i > 0; i--) {
        for (int j = 0; j <= 2 * h - 1; j++) {
            if (j == h / 2 + i - 1 || j == h / 2 - i + 1 || j == h / 2 + i - 2 + h || j == h / 2 - i + h) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

/*                    1 1 1 1 1
  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
0       *           *
1     *   *       *   *
2   *       *   *       *
3 *           *           *
2   *       *   *       *
1     *   *       *   *
0       *           *
*/
