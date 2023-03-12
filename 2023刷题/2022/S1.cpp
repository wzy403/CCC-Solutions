#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n >= 0){
        if(n % 5 == 0){
            ans++;
        }
        n -= 4;
    }
    cout << ans;
    return 0;
}
