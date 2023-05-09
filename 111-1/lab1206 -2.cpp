#include <iostream>

using namespace std;

typedef struct NODE{
	int data;
	struct NODE *next;
} NODE_t; 

int *merge (NODE_t *list1, NODE_t *list2, NODE_t *ptr){
    if(list1 == NULL && list2 == NULL)return 0;
    
    else if (list1 == NULL){
        ptr->next = list2;
        merge (list1, list2->next, ptr->next);
    }
    else if (list2 == NULL){
        ptr->next = list1;
        merge (list1->next, list2, ptr->next);
    }
    else if (list1->data > list2->data){
        ptr->next = list2;
        merge (list1, list2->next, ptr->next);
    }
    else {
        ptr->next = list1;
        merge(list1->next, list2, ptr->next);
    }
    
    return 0;
}
int main (){
	int v1[3] , v2[3] , v3[3];
	
	for (int i = 0 ; i < 3 ; i++){
		cin >> v1[i];
	}
	for (int i = 0 ; i < 3 ; i++){
		cin >> v2[i];
	}
	for (int i = 0 ; i < 3 ; i++){
		cin >> v3[i];
	}		
	NODE_t *list1, *list2, *list3, *ptr, *prev, *all1, *list_a, *all2, *list_b;
	
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
	
	ptr = new NODE_t;
	ptr->data = v3[0];
	ptr->next = NULL;
	list3 = ptr;
	prev = list3;
	for (int i = 1 ; i < 3 ; i++){
		ptr = new NODE_t;
		ptr->data = v3[i];
		ptr->next = NULL;
		prev->next = ptr;
		prev = ptr;
	}
	
	all1 = new NODE_t;
    list_a = new NODE_t;
    list_a = all1;
    merge(list1, list2, all1);
//    all2 = new NODE_t;
//    list_b = new NODE_t;
//    list_b = all2;
//    merge()
	
//	NODE_t *rec;
//	rec = merge (list1, list2);
//	rec = merge (rec, list3);
//	
	ptr = all1;
	while (ptr->next){
		cout << ptr->data << ", ";
		ptr = ptr->next; 
	}
	cout << ptr->data <<endl;
	
//	ptr = list2;
//	while (ptr->next){
//		cout << ptr->data << ", ";
//		ptr = ptr->next; 
//	}
//	cout << ptr->data ;
	return 0;
	
}
