#include <iostream>

using namespace std;

int main (){
	int num;
	cin >> num;
	if (num <= 0) return 0;
	if (num % 1000 >= 900){
		cout << "CM";
		num = num - 900;
	}
	if (num >= 1000){
		for (int i = 0 ; i < num /1000 ; i++){
			cout << "M";
		}
		num = num % 1000;
	}
	if (num % 500 >= 400){
		cout << "CD";
		num = num - 400;
	}
	if (num >= 500){
		for (int i = 0 ; i < num /500 ; i++){
			cout << "D";
		}
		num = num % 500;
	}
	if (num % 100 >= 90){
		cout << "XC";
		num = num - 90;
	}
	if (num >= 100){
		for (int i = 0 ; i < num /100 ; i++){
			cout << "C";
		}
		num = num % 100;
	}
	if (num % 50 >= 40){
		cout << "XL";
		num = num - 40;
	}
	if (num >= 50){
		for (int i = 0 ; i < num /50 ; i++){
			cout << "L";
		}
		num = num % 50;
	}
	if (num >= 10){
		for (int i = 0 ; i < num /10 ; i++){
			cout << "X";
		}
		num = num % 10;
	}
	if (num >= 5){
		cout << "V";
		for (int i = 0 ; i < num - 5 ; i++){
			cout << "I";
		}
		num = num % 5; 
	}
	if (num == 4){
		cout << "IV";
	}
	else {
		for (int i = 0 ; i < num ; i++){
			cout << "I";
		}
	}
	return 0;
}
