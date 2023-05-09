#include <iostream>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE_t;

int main() {
    int num = 0;
    cin >> num;
    int *a = new int[num];
    for (int i = 0; i < num; i++) {
        cout << "Input " << i << ": ";
        cin >> a[i];
    }
    NODE_t *head, *ptr, *curr, *curr1;
    //	if (!new NODE_t){
    //		cout << "Error";
    //	}
    ptr = new NODE_t;
    head = ptr;
    curr = ptr;

    for (int i = 0; i < num; i++) {
        ptr = new NODE_t;
        ptr->data = a[i];
        ptr->next = NULL;
        curr->next = ptr;
        curr = ptr;
    }
    int number;
    cout << "input another number behind 5th list block: ";
    cin >> number;

    // input the number between list and list
    ptr = new NODE_t;
    ptr->data = number;
    curr = ptr;
    ptr = head;
    for (int i = 0; i < 5; i++) {
        ptr = ptr->next;
    }
    curr1 = ptr->next;
    ptr->next = curr;
    curr->next = curr1;

    ptr = head;
    ptr = ptr->next;
    while (ptr->next) {
        cout << ptr->data << ", ";
        ptr = ptr->next;
    }
    cout << ptr->data;
    return 0;
}
