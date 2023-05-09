#include <iostream>
#include <string>
using namespace std;

int main (){
	string str, ss , ssf;
	int i = 0;
	int max_num = 0;
	int cont = 0;
	int j = 0;
	while (getline(cin , str)){
		ss += str;
		ss += '{';
		if(max_num < str.length()){
			max_num = str.length();
		}
		i++; 
	}

	int temp = 0;	
	while (j < ss.length()){
		if (ss[j] == '{'){
			for (int k = 0 ; k < max_num - (j - temp) ; k++){
				ssf += ' ';
			}
			temp = j + 1;
		}
		else {
			ssf += ss[j];
		}
		j++;
	}
	for (int k = 0 ; k < max_num ; k++){
		for (int l = 0 ; l < i ; l++){
			if (ssf[k + l * max_num] != ' '){
				cout << ssf[k + l * max_num];
			}
		}
	}

	return 0;
} 
