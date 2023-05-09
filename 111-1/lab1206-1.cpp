#include <iostream>
using namespace std;
 
typedef struct NODE{
    int data;
    struct NODE *next;
} NODE_t;
void *mergeee (NODE_t *head1, NODE_t *head2, NODE_t *ptr){
    if(head1 == NULL && head2 == NULL);
    
    else if (head1 == NULL){
        ptr->next = head2;
        mergeee (head1, head2->next, ptr->next);
    }
    else if (head2 == NULL){
        ptr->next = head1;
        mergeee (head1->next, head2, ptr->next);
    }
    else if (head1->data > head2->data){
        
        ptr->next = head2;
        mergeee (head1, head2->next, ptr->next);
    }
    else {
        ptr->next = head1;
        mergeee(head1->next, head2, ptr->next);
    }
    
    return 0;
}
 
int main() {
    int x[3] , y[3] , z[3] ;
    for (int i = 0 ; i < 3 ; i++){
		cin >> x[i];
	}
	for (int i = 0 ; i < 3 ; i++){
		cin >> y[i];
	}
	for (int i = 0 ; i < 3 ; i++){
		cin >> z[i];
	}	

    NODE_t *head1 ,*head2 ,*head_n ,*ptr, *head3 ,*prev, *n, *n1 , *head_n1;
	
	ptr = new NODE_t;
    ptr->data = z[0];
    ptr->next = NULL;
    head3 = ptr;
    prev = head3;

    for (int i = 1 ; i < 3 ; i++){
        ptr = new NODE_t;
        ptr->data = z[i];
        ptr->next = NULL;
        prev->next = ptr;
        prev = ptr;
    }
    
    ptr = new NODE_t;
    ptr->data = x[0];
    ptr->next = NULL;
    head1 = ptr;
    prev = head1;

    for (int i = 1 ; i < 3 ; i++){
        ptr = new NODE_t;
        ptr->data = x[i];
        ptr->next = NULL;
        prev->next = ptr;
        prev = ptr;
    }
    
    ptr = new NODE_t;
    ptr->data = y[0];
    ptr->next = NULL;
    head2 = ptr;
    prev = head2;

    
    for (int i = 1 ; i < 3 ; i++){
        ptr = new NODE_t;
        ptr->data = y[i];
        ptr->next = NULL;
        prev->next = ptr;
        prev = ptr;
    }
    
    n = new NODE_t;
    head_n = new  NODE_t;
    head_n = n;
    mergeee(head1, head2, n);
    head_n = head_n->next;
    
    n1 = new NODE_t;
    head_n1 = new NODE_t;
    head_n1 = n1;
    mergeee (head_n, head3, n1);
    head_n1 = head_n1 -> next;

    while (head_n1->next){
        cout << head_n1->data <<" ,";
        head_n1 = head_n1->next;
    }
    cout << head_n1->data;
return 0;
}
