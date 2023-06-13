#include <bits/stdc++.h>
using namespace std;

bool sortMap(pair<string, int> o1, pair<string, int> o2) {
    return o1.second > o2.second;
}

int main() {
    map<string, int> m;
    m["A"] = 1;
    m["B"] = 4;
    m["C"] = 3;
    m["D"] = 5;
    m["E"] = 2;
    sort(m.begin(), m.end(), sortMap);
    for (auto p : m) {
        cout << p.second << " ";
    }
}