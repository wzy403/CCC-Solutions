#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;
    int ans = 0;
    stack<int> number;
    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        if(temp != 0){
            ans += temp;
            number.push(temp);
        }else{
            ans -= number.top();
            number.pop();
        }
    }
    cout << ans;
    return 0;
}
