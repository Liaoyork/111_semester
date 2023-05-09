#include <iostream>
#include <string>
using namespace std;
//[[1, 2, 3], [54, 98, 7], [-199, 0, 7899]], x=-199
int main() {
    string a;
    string target;
    bool found = false;
    getline(cin, a);
    // a = "[[1, 2, 3], [54, 98, 7], [-199, 0, 7899]]x=7899";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'x') {
            target = a.substr(i + 2);
            a = a.substr(0, i);
            // cout << a <<endl;
            break;
        }
    }
    for (int i = 0; i < a.length(); i++) {
        string ans = "";
        if (a[i] == '-') {
            ans = "-" + ans;
            i++;
        }
        while (isdigit(a[i])) {
            ans = ans + a[i];
            i++;
        }
        // cout << ans << endl;
        if (ans == target) {
            found = true;
            cout << "true";
            break;
        }
    }
    if (!found) cout << "false";

    return 0;
}
