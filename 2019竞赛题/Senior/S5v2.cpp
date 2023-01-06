#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;
vector<vector<ll>> triangle;

ll maxNum(ll a, ll b, ll c){
    ll m = max(a,b);
    return max(m,c);
}

void rebuiled(ll s){
    n -= s;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < i+1; j++){
            triangle[i][j] = maxNum(triangle[i][j],triangle[i+s][j],triangle[i+s][j+s]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    triangle.resize(n);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < i+1; j++){
            ll num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }
    vector<ll> temp;
    ll num = k;
    temp.push_back(num);
    while(num > 2){
        if(num * 2 % 3 == 0){
            num = num * 2 / 3;
            temp.push_back(num);
        }else{
            num = num * 2 / 3 + 1;
            temp.push_back(num);
        }
    }
    temp.push_back(1);
    reverse(temp.begin(),temp.end());

    vector<ll> check;
    for(ll i = 0; i < temp.size()-1; i++){
        check.push_back(temp[i+1]-temp[i]);
    }

    for(auto&i : check){
        rebuiled(i);
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(auto&j : triangle[i]){
            ans += j;
        }
    }
    cout << ans;
    return 0;
}
