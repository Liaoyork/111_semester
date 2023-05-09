#include <iostream>
using namespace std;
int main()
{
	int a[2][10] = {{4, 5, 4, 92, 92, 80, 53, 1, 3, 1},
					{9, 7, 3, 4, 2, 6, 9, 5, 2, 4}};
	//	for (int i = 0 ; i < 10 ; i++){
	//		for (int j = 0 ; j < 10 ; j++){
	//			if (a[0][i] < a[0][j]){
	//				swap(a[0][i], a[0][j]);
	//				swap(a[1][i], a[1][j]);
	//			}
	//		}
	//	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[0][i] < a[0][j])
			{
				swap(a[0][i], a[0][j]);
				swap(a[1][i], a[1][j]);
				i = j;
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
