#include <iostream>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE_t;

NODE_t *merge(NODE_t *head1, NODE_t *head2) {
    NODE_t *ptr, *prev;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if (head1->data < head2->data) {
        ptr->next = head2;
        merge(head1, head2);
    } else {
        //		head2->next = merge (head1 , head2);
    }
}
int main() {
    int x[] = {1, 3, 6}, y[] = {2, 2, 5, 7, 9};

    NODE_t *head1, *head2, *head3, *ptr, *prev;

    ptr = new NODE_t;
    ptr->data = x[0];
    ptr->next = NULL;
    head1 = ptr;
    prev = head1;

    for (int i = 1; i < 3; i++) {
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

    for (int i = 1; i < 5; i++) {
        ptr = new NODE_t;
        ptr->data = y[i];
        ptr->next = NULL;
        prev->next = ptr;
        prev = ptr;
    }

    while (ptr->next) {
        cout << ptr->data << " ,";
        ptr = ptr->next;
    }
    cout << ptr->data;

    return 0;
}
