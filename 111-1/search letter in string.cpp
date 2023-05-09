#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int f_num(int);
int main (){
	string n, ss;
	bool terrible = true;
	cin >> n;
	for (int i = 0 ; i < 11 ; i++){
		ss += to_string(f_num(i));
	}
	size_t found = ss.find(n);
	cout << found;
	if (found >= 0 && found <= 15) cout <<"True";
	else cout <<"False";
	return 0;
}
int f_num(int n){
	if (n <= 1) return 1;
	else return f_num(n-1)+f_num(n-2);
}

