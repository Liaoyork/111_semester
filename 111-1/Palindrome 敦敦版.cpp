#include <iostream>
#include <time.h>
#include <string>
using namespace std;
// axilixbab

bool test(string a){
    int i;
    bool right = true;;
    if(a.length()==1)return false;//一個字母不算是回文
    for(i=0; i<a.length()/2; i++){
        if(a[i]!=a[a.length()-1-i]){//是否回文
            right = false;
        }
    }
    return right;
    
}

int main() {
    string a;
    getline(cin, a);
    int n=0;
    string answers[100];//一個可以記錄有回文字串的陣列
    for(int i=0; i<100; i++){
        answers[i] = " ";
    }
    for(int i=0; i<a.length()-1; i++){//瘋狂迴圈 找出所有可能的字串
        string curr="";
        for(int j=i; j<a.length(); j++){//瘋狂迴圈 找出所有可能的字串
            curr+=a[j];
            bool is_palindrome = test(curr);//是否回文
            if(is_palindrome){
                bool had = false;
                for(int i=0; i<100; i++){//把回文的字串存起來
                    if(answers[i] == " ")break;
                    if(curr == answers[i])had = true;
                }
                if(!had){//看看有沒有出現過
                    cout <<curr<<endl;
                    answers[n] = curr;
                    n++;
                }
            }
        }
    }
    return 0;
}
