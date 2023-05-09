#include <iostream>
#include "BST.h"

using namespace std;

void gogo(node *ptr){
    gogo(ptr->left);
    printBST(prt->left->dataPtr);
    process(ptr->left);
    gogo(ptr->right);
}

bool findD = false;

node* gogoD(node *root, void *dltKey){
    if (root == NULL) return root;
    else if (*(int*)dltKey < *(int*)(root->dataPtr)) root->left = gogoD(root->left, dltKey);
    else if (*(int*)dltKey > *(int*)(root->right)) root-> right = gogoD(root->left, dltKey);
    else {
        //with no child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            findD = true;
            return root;
        }
        //have one child
        else if (root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
            findD = true;
            return root;

        }
        else if (root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
            findD = true;
            return root;
        }
        //have two child
        else {
            findD = true;
            node *temp = root->right;
            root->dataPtr = temp->dataPtr;
            root->right = gogoD(root->right, temp->dataPtr);
        }
    }

    /*
    static node *ans = NULL;
    if (ptr->left != NULL) {
        if(ans == NULL) ans = gogoD(ptr->left,dltKey);
    }
    if (ptr->right != NULL) {
        if(ans == NULL) ans = gogoD(ptr->right,dltKey);
    }
    if (*(int*)dltKey == *(int*)(ptr->dataPtr)){
        ans = ptr;
    }
    
    return ans;
    */
}

BST::BST(int (*compare)(void* argu1, void* argu2)){
    root = NULL;
    count = 0;
}
BST::~BST(){
    ;
}
node* BST::_insert(node* root, node* newPtr){
   return root;
}
bool BST::BST_Insert(void* data){
    int a=*(int*)data;
    node *ptr = root , *curr;
    bool isLeft;
    while (1){
        if (a > *(int*)ptr->dataPtr){
            if (ptr->right = NULL) {
                isLeft = false;
                break;
            }
            ptr = ptr->right;
        } else if (a < *(int*)ptr->dataPtr){
            if (ptr->left = NULL) {
                isLeft = true;
                break;
            }
            ptr = ptr->left;
        }
    }
    
    curr = ptr;
    ptr = new node;
    if (ptr) count++;

    if (isLeft) {
        curr->left = ptr;
    } else {
        curr->right = ptr;
    }
    ptr->dataPtr = data;
    return true;
}
bool BST::BST_Delete(void* dltKey){
    node *key;
    gogoD(root, dltKey);
    if (!findD) return false;
    count--;
    findD = false;
    return true;
}
void BST::BST_Traverse(void (*process)(void* dataPtr)){
    ;
}
bool BST::BST_Empty(){
    if(count) return false;
    return true;
}
bool BST::BST_Full(){
    node *ptr;
    ptr = new node;
    if (&ptr) {
        delete ptr;
        return false;
    }
    return true;
}
int BST::BST_Count(){
    return count;
}

