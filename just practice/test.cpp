#include <cstring>
#include <iostream>
#include <stack>

using namespace std;
int main() {
    stack<char> stk;
    string line;
    while (cin >> line) {
        char *lin = new char[line.length() + 1];
        strcpy(lin, line.c_str());
        stk.push(lin[0]);
        for (unsigned int x = 1; x <= strlen(lin); x++) {
            if (stk.top() != lin[x]) {
                if (stk.size() == 1) {
                    cout << stk.top();
                    stk.pop();
                } else if (stk.size() == 2) {
                    cout << stk.top() << stk.top();
                    while (!stk.empty()) {
                        stk.pop();
                    }

                } else {
                    cout << stk.size() << stk.top();
                    while (!stk.empty()) {
                        stk.pop();
                    }
                }
                stk.push(lin[x]);
            }

            else
                stk.push(lin[x]);
        }
        cout << endl;
        while (!stk.empty()) {
            stk.pop();
        }
        delete[] lin;
    }

    return 0;
}