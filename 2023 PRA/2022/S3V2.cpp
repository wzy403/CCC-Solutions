#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,m;
    ll k;
    cin >> n >> m >> k;
    if(n == 2){
        if(k == 3){
            cout << 1 << ' ' << 2;
        }else if(k == 2){
            cout << 1 << ' ' << 1;
        }else{
            cout << -1;
        }
        return 0;
    }
    vector<int> ans(n,0);
    int pos;
    int check = false;
    if(n == k){
        for(int i = 0; i < n; i++){
            cout << 1 << ' ';
        }
        return 0;
    }
    ans[0] = 1;
    ans[1] = 3;
    for(int i = 2; i < n; i++){
        if(k - ans[i-1] == n-i){
            check = true;
            pos = i;
            break;
        }else{
            ans[i] = ans[i-1] + 2;
        }
    }
    if(ans[n-1] == k){
        pos = n;
        check = true;
    }
    if(check){
        cout << 1 << ' ' << 2 << ' ';
        int last = 2;
        for(int i = 2; i < pos; i++){
            if(last == 2){
                cout << 1 << ' ';
                last = 1;
            }else{
                cout << 2 << ' ';
                last = 2;
            }
        }

        for(int i = pos; i < n; i++){
            cout << last << ' ';
        }
    }else{
        cout << -1;
    }

    return 0;
}
