#include <iostream>

using namespace std;

typedef struct NODE{
	int data;
	struct NODE *next;
} NODE_t; 
int main (){
	int v[5] = {1, 2, 5, 4, 3};
	int r = 0;
	NODE_t *list , *ptr , *prev;
	ptr = new NODE_t;
	ptr->data = v[0];
	list = ptr;
	ptr->next = NULL;
	prev = list;
	for (int i = 1 ; i < 5 ; i++){
		ptr = new NODE_t;
		ptr->data = v[i];
		ptr->next = NULL;
		prev->next = ptr;
		prev = ptr;
	}
	ptr->next = list;
	ptr = list;
//	ptr = list;
//	while (ptr->next){
//	cout << ptr->data << ", ";		
//	ptr = ptr->next; 
//	}
//	cout << ptr->data <<endl;
	
	while (1){
		cin >> r;
		if (r == 10) break;
		else {
			if (r<0){
				r = -r;
				for (int k = r ; k >= 0 ; k--){
					ptr = ptr->next;
				}
				cout << ptr->data << "->";
				for (int i = 0 ; i < 3 ; i++){
					ptr = ptr->next;
					cout << ptr->data << "->";		 
				}
				ptr = ptr->next;
				cout << ptr->data;
				cout << endl;
			}
			else if (r>=0){
				r = abs((r-r/5*5)-5) ;
				for (int k = r ; k > 0 ; k--){
					ptr = ptr->next;
				}
				cout << ptr->data << "->";
				for (int i = 0 ; i < 3 ; i++){
					ptr = ptr->next;
					cout << ptr->data << "->";		 
				}
				ptr = ptr->next;
				cout << ptr->data;
				cout << endl;
			}
		}
	}	
}	

