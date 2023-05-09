#include <iostream>
using namespace std;
void sum(int, int , int&);
int main (){
	int n = 50;
	int *p = &n;
	cout <<"The value of p is "<<*p<<endl;
	cout <<"The address of p is "<<p<<endl;
	int n1 = 40;
	*p = n1;
	cout <<"The value of p is "<<*p<<endl;
	cout <<"The address of p is "<<p<<endl;
	cout <<"The value of p is "<<&n1<<endl;
	cout <<"The size of p is "<<sizeof(p)<<endl;
	int x=2,y=3,z;
	sum(x,y,z);
	cout <<x<<"+"<<y<<"="<<z<<endl;
	int a = 5;
	int &c = a;
	cout <<c<<endl;
	c = 10;
	cout <<a;
} 
void sum(int x, int y , int &z){
	z=x+y;
}
