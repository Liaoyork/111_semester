#include <iostream>

using namespace std;

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE_t;

int main (){
	int v[8] = {1,5,6,3,2,8,0,9};
	int n;
	cin >> n;
	NODE_t *head, *ptr, *prev;
	
	ptr = new NODE_t;
	ptr->data = v[0];
	ptr->next = NULL;
	head = ptr;
	prev = head;
	for (int i = 1 ; i < 8 ; i++){
		ptr = new NODE_t;
		ptr->data = v[i];
		ptr->next = NULL;
		prev->next = ptr;
		prev = ptr;
	}
	
	ptr = head; 
	if (ptr->data == n){
		ptr = head;
		head = ptr->next;
		delete ptr;
		ptr = NULL;
	}

	else if (head) {
		ptr = head;
		while(ptr->next && ptr->data != n){
			prev = ptr;
			ptr = ptr->next;
		}
		if (ptr->data == n || ptr->next != NULL){
			prev->next = ptr->next;
			delete ptr;
			ptr = NULL;
		}
	}
	
	ptr = head;
	while (ptr->next){
		cout << ptr->data << ", ";
		ptr = ptr->next; 
	}
	cout << ptr->data <<endl;

}
