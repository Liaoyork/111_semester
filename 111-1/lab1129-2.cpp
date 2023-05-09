#include <iostream>
using namespace std;
int main (){
	int n;
	cin >>n;
	int *num = new int[n];
	for (int i = 0 ; i < n ; i++){
		cin >>num[i];
	}
	
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++){
			if (num[i] < num[j]){
				int temp = num[i]; 
				num[i] = num[j];
				num[j] = temp;	
			}
		}
	}
	for (int i = 0; i < n ;i++){
		if (i==n-1)
			cout <<num[i];
		else
			cout <<num[i]<<", ";
	}
	return 0;
}
