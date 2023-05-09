#include <iostream>
using namespace std;

int H(int ,int);
int main (){
	int m, n, p;
	cin >> m >> n >> p;
	cout << H(H(m,n),p);
	return 0;
}
int H (int m, int n){
	if (n == 0) return m;
	if (m == 0) return n;
	else {
		if (m<n) swap(m,n);
		return H(m-n,n);
	}
}
