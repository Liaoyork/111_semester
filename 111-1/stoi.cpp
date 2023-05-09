#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

int main (){
	string ss;
	cin >> ss;
	int k = 1;
	int n;
	n = ss.length();
	while (n-1){	
		k= k * 10;
		n--;
	}
	cout <<  ((int)(ss[0] - '0')) * k;
	for (int i = 1 ; i < ss.length(); i++){
		if ((int)(ss[0] - '0') == 0) continue;
		else if (i != ss.length()-1 ) {
			int w = 1;
			int c = ss.length() - i;
			while (c >= 2){	
				w = w * 10;
				c--;
			}
			if (!(int)(ss[i] - '0')); 
			else if ((int)(ss[i] - '0') == 0){
				break;
			}
			else cout << ", " << (int)(ss[i] - '0') * w ;
		}
		else if ((int)(ss[i] - '0') != 0){
			cout << ", " <<ss[i];
		}
	}
//	cout << (int)(ss[0] - '0') + 1;

	return 0;
}



