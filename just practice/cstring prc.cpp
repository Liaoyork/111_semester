#include <iostream>
#include <cstring>
using namespace std;

int main (){
	char a[10] = "abcdf";
	char b[10];
	strcpy(b,a);
	cout << b;
}
