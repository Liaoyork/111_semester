#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct NODE{
	int dig;
	struct NODE *next;
}NODE_t; 
int main (){
	int n, i;
	cout << "input: ";
	cin >> n;
	n = i;
	NODE_t *head, *ptr, *prev;
	ptr = new NODE_t;
	ptr -> next = NULL;
	head = ptr;
	ptr = head;
	while (i){
		ptr = new NODE_t;
		ptr -> dig = n%10;
		ptr -> next = NULL;
		i = i/10;
		prev -> next = ptr;
		prev = ptr;
	}
	ptr = head;
	while (ptr -> next){
		cout <<ptr -> next<<",";
		ptr = ptr -> next;
	}
	cout <<ptr -> dig <<endl;
	return 0;
} 
