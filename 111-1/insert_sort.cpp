#include <iostream>
using namespace std;
int main()
{
	int i = 0, k = 0, m = 0;
	int temp = 0;
	int MAX_RANGE;
	cout << "�п�J�ݭn�ƤJ���Ʀr�Ӽ�: ";
	cin >> MAX_RANGE;
	int a[MAX_RANGE], b[MAX_RANGE];

	for (i = 0; i < MAX_RANGE; i++)
	{
		cout << "�п�J�Ʀr" << i + 1 << ": ";
		cin >> a[i];
	}
	i = 0;
	for (k = 0; k < MAX_RANGE; k++)
	{
		cout << a[k] << " ";
	}
	cout << endl;
	k = 0;
	b[0] = a[0];
	for (i = 0; i < MAX_RANGE; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				for (m = 0; m < MAX_RANGE; m++)
				{
					cout << a[m] << " ";
				}
				cout << endl;
				i = j;
			}
		}
		cout << endl;
	}
	return 0;
}
