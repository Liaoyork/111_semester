#include "BST.h"
using namespace std;

int compareInt(void* num1, void* num2);
void printBST(void* num1);
void printMenu();

int main(){
    int (*fp)(void*,void*);
    BST xx(fp);
    node *input;
    while (1){
        int mod = 0;
        printMenu();
        cin >> mod;
        switch(mod){
            case 1:
                cout << "Enter an interger: "; cin >> input->dataPtr;
                xx.BST_Insert(input->dataPtr);   break;
            case 2:
                if (xx.BST_Empty()) {
                    cout << "The BST is empty." << endl;
                    continue;
                }
                cout << "Enter an interger: "; cin >> input->dataPtr;
                xx.BST_Delete();   break;
            case 3:
                if (xx.BST_Empty()) {
                    cout << "The BST is empty." << endl;
                    continue;
                }
                gogo(); break;
            case 4:
                if (!xx.BST_Full()) {
                    cout << "BST is not full yet" << endl;
                }
                break;
            case 5:
                cout << "There are " << xx.BST_Count() << " nodes in BST.";    break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
int compareInt(void* num1, void* num2){
    //int *nu1 = *(int*)num1;
    //int *nu2 = *(int*)num2;
    //if (nu2 > nu1) 
}
void printBST(void* num1){
    cout << *(int*)num1 << " ";   
}
void printMenu(){
    cout << "The following are six options for your BST:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Print the BST" << endl;
    cout << "4. Check the BST is full or not" << endl;
    cout << "5. Print the number of nodes in BST" << endl;
    cout << "6. Exit" << endl;
    cout << "Please enter: ";
}
