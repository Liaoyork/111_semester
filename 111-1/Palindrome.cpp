#include <iostream>
#include <string>
using namespace std;
void Pa(string , int);
int main (){
	string ss;
	string mm;
	int k = 0;
	cin >> ss;
	int i = 0;
	int j = ss.length() - 1;
	while (i != ss.length()/2){
		if (ss[i] == ss[j]){
			mm += ss[i];
		}
		i++;
		j--;
	}
	cout << i << endl;
	if (mm.length() == 0) return 0;
	mm += ss[i];
	cout << mm << endl;
	
	for (int i = j - 1; i >= 0 ; i--){
		mm += mm[i];
	}

	if (mm.length() == 1) return 0;
	Pa(mm , mm.length()/2 + 1);
	return 0;
} 
void Pa (string mm , int n){
	if (n == mm.length()){
		for (int i = 0 ; i < mm.length() ; i++){
			cout << mm[i];
		}
		cout << endl;
		return;
	}
	Pa (mm , n+1);
	if (mm.length()/2 + 1 == n) return;
	for (int i = n - 1 ; i >= mm.length() - n; i--){
		cout << mm[i];
	}
	cout << endl; 
}
