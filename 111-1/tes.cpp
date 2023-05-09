#include <iostream>
using namespace std;
int main (){
	int a[4][7] = {-1};
	for (int i = 0 ; i < 4 ; i++){
		for (int j = 0; j < 7 ; j++ ){
			cout << a[i][j];
		}
		cout <<endl;
	}
}

