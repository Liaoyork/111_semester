#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> ori_num;
vector<string> ans;

bool rec(int start, int end, string ss, map<string, int> dic) {
}
bool sortStr(string &s1, string &s2) {
    return s1 > s2;
}
int main(int argc, char *argv[]) {
    map<string, int> dictionary;
    ifstream in(argv[1]);
    string ss;
    int amo;
    while (in >> ss >> amo) {
        dictionary.insert(pair<string, int>(ss, 0));
        ori_num.insert(pair<string, int>(ss, amo));
    }
    string testcase = argv[2];
    if (rec(0, 0, testcase, dictionary)) {
        cout << "True\n";
        for (auto p = dictionary.begin(); p != dictionary.end(); p++) {
            cout << p->first << ": " << p->second << "(" << ori_num[p->first] << "->" << ori_num[p->first] - p->second << ")\n";
        }
        sort(ans.begin(), ans.end(), sortStr);
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans.at(i) << " ";
        }
        cout << endl;
    } else {
        cout << "False" << endl;
    }
}
