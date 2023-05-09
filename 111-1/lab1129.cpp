#include <iostream>
#include <string>
using namespace std;
int main (){
	int n;
	cin >>n;
	string *stu_name = new string [n];
	for (int i = 0 ; i < n ; i++){
		cin >>stu_name[i];
	}
	
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++){
			if (stu_name[i] < stu_name[j]){
				string temp = stu_name[i];
				stu_name[i] = stu_name[j];
				stu_name[j] = temp;	
			}
		}
	}
	for (int i = 0; i < n ;i++){
		if (i==n-1)
			cout <<stu_name[i];
		else
			cout <<stu_name[i]<<", ";
	}
	return 0;
} 
