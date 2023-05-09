#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream in;
    ofstream out;
    in.open("file.txt");
    out.open("123.txt");
    string input;
    while (getline(in, input)) {
        string ans = "";
        for (int i = 0; i < input.length(); i++) {
            if (input.substr(i, 3) == "cin") {
                i = i + 2;
                if (input[i + 2] == ' ') {
                    for (int k = 0; k < i + 2; k++) {
                        ans[k] = input[k];
                    }
                    ans += " >>";
                    while (input[i + 2] == ' ') {
                        i++;
                    }
                    i += 2;
                    for (int k = i; k < input.length(); i++) {
                        ans[k] = input[k];
                    }
                } else if (input[i + 1] != ' ') {
                    for (int k = 0; k < i + 1; k++) {
                        ans[k] = input[k];
                    }
                    ans += " >>";
                    i += 2;
                    for (int k = i; k < input.length(); i++) {
                        ans[k] = input[k];
                    }
                }
            } else if (input.substr(i, 4) == "cout") {
                i += 3;
                if (input[i + 2] == ' ') {
                    for (int k = 0; k < i + 2; k++) {
                        ans[k] = input[k];
                    }
                    while (input[i + 2] == ' ') {
                        i++;
                    }
                    ans += "<<";
                    i += 2;
                    for (int k = i; k < input.length(); i++) {
                        ans[k] = input[k];
                    }
                } else if (input[i + 1] != ' ') {
                    for (int k = 0; k < i + 1; k++) {
                        ans[k] = input[k];
                    }
                    ans += " <<";
                    i += 2;
                    for (int k = i; k < input.length(); i++) {
                        ans[k] = input[k];
                    }
                }
            } else {
                ans = input;
            }
        }
        out << ans;
        out << endl;
    }
    return 0;
}