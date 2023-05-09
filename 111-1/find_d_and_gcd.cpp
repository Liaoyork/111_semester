#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a <= b)
	{
		swap(a, b);
		gcd(a % b, b);
	}
}
int main()
{
	string ss;
	getline(cin, ss);
	int space = 0;
	for (int i = 0; i < ss.length(); i++)
	{
		if (ss[i] == ' ')
		{
			space++;
		}
	}
	int num = space + 1;
	int *a = new int[num];
	int j = 0;
	if (ss[0] != '0')
	{
		a[0] = stoi(&ss[0]);
		j++;
		if (a[0] == 1)
		{
			j--;
		}
	}
	bool plus = true;
	for (int i = j; i < ss.length(); i++)
	{
		if (ss[i] == ' ' && ss[i + 1] != '0' && ss[i + 1] != '1')
		{
			a[j] = stoi(&ss[i + 1]);
			j++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		cout << "(";
		plus = true;
		for (int k = 2; k <= a[i]; k++)
		{
			if (plus && a[i] % k == 0)
			{
				cout << k;
				plus = false;
			}
			else if (a[i] % k == 0)
			{
				cout << ", " << k;
			}
		}
		if (i == j - 1)
			cout << ")";
		else
			cout << "), ";
	}
	int temp = gcd(a[0], a[1]);
	for (int i = 2; i < j; i++)
	{
		if (temp == 1)
			break;
		temp = gcd(temp, a[i]);
	}
	cout << endl
		 << temp;
	return 0;
}
