#include <iostream>

using namespace std;

typedef struct NODE{
	int data;
	struct NODE *next;
} NODE_t; 
int main (){
	int v1[3] = {1, 2, 4}, v2[3] = {1, 3, 4};
	
	NODE_t *list1, *list2, *ptr, *prev;
	
	ptr = new NODE_t;
	ptr->data = v1[0];
	ptr->next = NULL;
	list1 = ptr;
	prev = list1;
	for (int i = 1 ; i < 3 ; i++){
		ptr = new NODE_t;
		ptr->data = v1[i];
		ptr->next = NULL;
		prev->next = ptr;
		prev = ptr;
	}
	
	ptr = new NODE_t;
	ptr->data = v2[0];
	ptr->next = NULL;
	list2 = ptr;
	prev = list2;
	for (int i = 1 ; i < 3 ; i++){
		ptr = new NODE_t;
		ptr->data = v2[i];
		ptr->next = NULL;
		prev->next = ptr;
		prev = ptr;
	}
	
	ptr = list1;
	
	while (ptr->next){
		cout << ptr->data << ", ";
		ptr = ptr->next; 
	}
	cout << ptr->data <<endl;
	
	ptr = list2;
	while (ptr->next){
		cout << ptr->data << ", ";
		ptr = ptr->next; 
	}
	cout << ptr->data ;
	return 0;
	
}
