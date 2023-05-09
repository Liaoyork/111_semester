#include <iostream> 
using namespace std;
int w=0;
int sum(int n){
	int k;
	if (n<10){
		w=w+n;
		return w;
	}
	else{
		k=n%10;
		w=w+k;
		n=n/10;
		return sum(n);
	} 	
}
int main (){
	int n;
	cin >>n;
	
	cout <<sum(n);
}
