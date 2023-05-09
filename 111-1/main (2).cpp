//
//  main.cpp
//  target&combination
//
//  Created by 簡敦賢 on 2022/12/28.
//

#include <iostream>
#include <string>

using namespace std;

int dfs(int *p, int target, int num, string tem){
    int ans=0;

    if(target==0){
        cout << tem << endl;
        return 1;
    }else if (target<0){
        return 0;
    }
    if(num==0)return 0;
    for(int i=0; i<num; i++){
        
        int *ptr = new int[num-i-1];
        int k=0;
        for(int j=i+1; j<num; j++){
            ptr[k] = p[j];
            k++;
        }
        ans += dfs(ptr, target-p[i], num-1, tem+to_string(p[i])+" ");
        
    }
    return ans;
}

int main() {
    
    int *ptr;
    int n=5;
    int arr[5] = {1, 2, 3, 6, 5};
    ptr = &arr[0];
    
    cout << dfs(ptr, 6, n, "");
    
    return 0;
}
