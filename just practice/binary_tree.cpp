#include <iostream>
using namespace std;

typedef struct tree {
    int data;
    struct tree *left, *right;
} tree_t;
int main() {
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    tree_t *head, *ptr, *curr;

    ptr = new tree_t;
    head = ptr;
    curr = ptr;
    ptr->data = a[0];
    ptr = new tree_t;
    curr->left = ptr;
    ptr->data = a[1];
    curr = ptr;
    ptr = new tree_t;
    ptr->data = a[3];
    curr->left = ptr;
    ptr->left = NULL;
    ptr->right = NULL;
}