#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int count_char[26]={0};		//count the number of letter appear
    int rank[26];				//remember the letter location 0~25 == a~z
    
    for(int i=0; i<26; i++)rank[i]=i;
    
    string a;
    cin >> a;
    
    for(int i=0; i<a.length(); i++){		//count the number appear
        char letter = a[i];
        count_char[int(letter-'a')]++;
        
    }
    
    for(int i=25; i>0; i--){							//bubble sort
        for(int j=0; j<i; j++){
            if(count_char[j]<count_char[j+1]){			//times
                swap(count_char[j], count_char[j+1]);
                swap(rank[j], rank[j+1]);
            }
            else if(count_char[j]==count_char[j+1]){	//if time the same
                if(rank[j] > rank[j+1]){					//compare ASCII
                    swap(count_char[j], count_char[j+1]);
                    swap(rank[j+1], rank[j]);
                }
            }
        }
    }
    //cout << ans;
    for(int i=0; i<26; i++){
        while(count_char[i]--) cout << char(int('a')+rank[i]);
        //cout << count_char[i];
    }
    
    return 0;
}
