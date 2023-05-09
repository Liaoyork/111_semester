#include <iostream>
#include <string>
using namespace std;

int main (){
	string ss;
	getline(cin , ss);
	int max_len = 0;
	int i_t = 0;
	int j_t = 0;
//	for (int i = 0 ; i < ss.length() ; i++){
	for (int j = 0 ; j < ss.length() ; j++){
		for (int k = j - 1 ; k >= i_t ; k--){
			if (max_len < j - i_t && k == i_t){
				max_len = j - i_t;
				i_t = k;
				j_t = j;
			}
//			else if (j - k == 1 && ss[k] == ss[j]){
//				i_t = k;
//			}
			else if (max_len < j - i_t && ss[k] == ss[j]){
				max_len = j - i_t;
				i_t = k;
				j_t = j - 1;
			}
			
			else if (ss[k] != ss[j]);
		}
	}
//	}
//	int len = 0;
//	int k = 0;
//	int i_temp = 0;
//	int j_temp = 0;
//	for (int j = 1 ; j < ss.length() ; j++){
//		for (int k = i_temp ; k < j ; k++){
//			if (ss[k] != ss[j]) {
//				continue;
//			}
//			else if (len < j_temp - i_temp + 1 && ss[k] == ss[j]){
//				len = j_temp - i_temp;
//				k = j;
//				i_temp = j_temp ;
//				j_temp = j;
//			}
//		} 
//	}
	cout << i_t << " " << j_t << endl;
	for (int i = i_t ; i <= j_t; i++){
		cout << ss[i];
	}
	cout << " (" << j_t - i_t + 1 << ")";
}
