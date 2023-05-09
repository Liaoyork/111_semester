#include <iostream>
#include <string>
using namespace std;

int main (){
	string arr;
	int a[100] = {0};
	int i = 0;
	int j = 0;
	getline(cin , arr);
	for (int i = 0 ; i < arr.length() ; i++){
		if (arr[i] >= '0' && arr[i] <= '9'){
			a[j] = stoi(&arr[i]);
			j++;	
		}
	}
	for (int k = 0 ; k <= j ; k++){
		for (int l = 0 ; l <= j ; l++){
			if (a[k] < a[l]){
				swap (a[k] , a[l]);
			}
		}
	}
	cout << "[";
	for (int k = 1 ; k < j ; k++){
		cout << a[k] << ", ";
	}
	cout << a[j] << "]";
	return 0;
} 
