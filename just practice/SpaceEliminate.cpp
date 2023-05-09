#include <iostream>
#include <string>
using namespace std;

int main() {
    string ss;
    string ans = "";
    getline(cin, ss);
    int j = 0;
    int con = 0;
    for (int i = 0; i < ss.length(); i++) {
        con = 0;
        while (ss[i] == ' ' || i == ss.length() - 1) {
            con++;
            i++;
        }
        if (con % 2 == 1 && con != 0) {
            ans += ' ';
        }
        if (ss[i] >= 'a' && ss[i] <= 'z' || ss[i] >= 'A' && ss[i] <= 'Z' || ss[i] == '.') {
            ans += ss[i];
        }
    }
    cout << ans;
    return 0;
}
