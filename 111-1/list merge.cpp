//#include <iostream>
//using namespace std;
//
//typedef struct NODE{
//	int data;
//	struct NODE *next;
//} NODE_t;
//
//
//NODE_t *mergee (NODE_t * , NODE_t *);
//int main (){
//	int a[5] = {2 ,7 ,8 ,13, 17};
//	int b[4] = {1, 5, 6, 10};
//	
//	NODE_t *head1, *head2 ,*ptr , *curr;
//	
//	int i = 1;
//	ptr = new NODE_t;
//	
//	head1 = ptr;
//	curr = head1;
//	
//	ptr->data = a[0];
//	ptr->next = NULL; 
//	
//	while (i < 6){
//		ptr = new NODE_t;
//		ptr->data = a[i];
//		ptr->next = NULL;
//		curr->next = ptr;
//		curr = curr->next;	
//		i++;
//	}
//
//	//---
//	i = 1;
//	head2 = ptr;
//	curr = head2;
//	
//	ptr->data = b[0];
//	ptr->next = NULL; 
//	
//	while (i < 5){
//		ptr = new NODE_t;
//		ptr->data = b[i];
//		ptr->next = NULL;
//		curr->next = ptr;
//		curr = curr->next;	
//		i++;
//	}
//	
//	ptr = mergee(head1,head2);
//	
//	while (ptr->next){
//		cout << ptr->data << ", ";
//		ptr = ptr->next;
//	}
//	cout << ptr->data;
//
//	return 0;
//} 
//NODE_t *mergee (NODE_t *head1 , NODE_t *head2){
//	NODE_t *ptr, *ptr2;
//
//	if (head1 == NULL) return head2;
//	if (head2 == NULL) return head1;
//	else if (head1->data > head2->data){
//
//		ptr = head2->next;
//		head2->next = head1;
//		head1->next = ptr;
//		head1 = head1->next;
//		
//		mergee(head1 , ptr);
//	}
//	else {
//		ptr = ptr->next;
//		mergee(head1 , ptr);
//	}
//	
//}
