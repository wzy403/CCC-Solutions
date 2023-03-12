#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n,m,k;
    //n=size; m=lim; k=sum
    cin >> n >> m >> k;
    if(n == k){
        for(ll i = 0; i < n; i++){
            cout << m << ' ';
        }
        return 0;
    }
    vector<ll> ans(n);
    ll sum = 0;
    ll add = 1;
    ll i = 0;
    while(i < n && add <= m && sum + add < k){
        sum += add;
        ans[i] = add;
        i++;
        add++;
    }
    bool haveAns = false;
    if(i == n - 1 && sum + add == k){
        ans[i] = add;
        haveAns = true;
    }else{
        ll rAdd = 1;
        ll counter = 1;
        while(i < n){
            if(counter >= add){
                break;
            }
            if(rAdd >= add){
                rAdd = 1;
            }
            if(sum + ans[i-rAdd] < k - (n-i-1)){
                ans[i] = rAdd;
                sum += ans[i-rAdd];
                i++;
                counter = 1;
                rAdd++;
                continue;
            }else if(sum + ans[i-rAdd] == k - (n-i-1)){
                for(int x = i; x < n; x++){
                    ans[x] = rAdd;
                }
                haveAns = true;
                break;
            }
            rAdd++;
            counter++;
        }
    }
    if(haveAns){
        for(auto &i : ans){
            cout << i << ' ';
        }
    }else{
        cout << -1;
    }
    return 0;
}
