#include <iostream>
#include <string>
using namespace std;

int fake = 0;
void permutations(string str, int i, int n)
{
    if (i == n - 1 && fake == 0)
    {
        cout << "[";
        for (int k = 0; k < str.length() - 1; k++)
        {
            cout << str[k] << ", ";
        }
        cout << str[str.length() - 1] << "]";
        fake++;
        return;
    }
    else if (i == n - 1)
    {
        cout << ", [";
        for (int k = 0; k < str.length() - 1; k++)
        {
            cout << str[k] << ", ";
        }
        cout << str[str.length() - 1] << "]";
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(str[i], str[j]);
        permutations(str, i + 1, n);
        swap(str[i], str[j]);
    }
}

int main()
{
    string str, str_num;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ',' && str[i] != ' ' && str[i] != ']' && str[i] != '"' && str[i] != '[')
        {
            str_num += str[i];
        }
    }
    permutations(str_num, 0, str_num.length());
    return 0;
}
