#include <iostream>
#include <time.h>
#include <string>
using namespace std;
// axilixbab

bool test(string a){
    int i;
    bool right = true;;
    if(a.length()==1)return false;//�@�Ӧr������O�^��
    for(i=0; i<a.length()/2; i++){
        if(a[i]!=a[a.length()-1-i]){//�O�_�^��
            right = false;
        }
    }
    return right;
    
}

int main() {
    string a;
    getline(cin, a);
    int n=0;
    string answers[100];//�@�ӥi�H�O�����^��r�ꪺ�}�C
    for(int i=0; i<100; i++){
        answers[i] = " ";
    }
    for(int i=0; i<a.length()-1; i++){//�ƨg�j�� ��X�Ҧ��i�઺�r��
        string curr="";
        for(int j=i; j<a.length(); j++){//�ƨg�j�� ��X�Ҧ��i�઺�r��
            curr+=a[j];
            bool is_palindrome = test(curr);//�O�_�^��
            if(is_palindrome){
                bool had = false;
                for(int i=0; i<100; i++){//��^�媺�r��s�_��
                    if(answers[i] == " ")break;
                    if(curr == answers[i])had = true;
                }
                if(!had){//�ݬݦ��S���X�{�L
                    cout <<curr<<endl;
                    answers[n] = curr;
                    n++;
                }
            }
        }
    }
    return 0;
}
