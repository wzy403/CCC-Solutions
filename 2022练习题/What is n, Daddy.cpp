#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    set<int>answer;
    int r = 0;
    if(n <= 5){
        for(int i = 0; i < n; i++){
            answer.insert(i);
            answer.insert(n-i);
            if(n-i == i)
                r++;
        }
    }else{
        for(int i = n - 5; i <= 5; i++){
            answer.insert(i);
            answer.insert(n-i);
            if(n-i == i)
                r++;
        }
    }
    cout << (answer.size()/2) + r;
    return 0;
}
