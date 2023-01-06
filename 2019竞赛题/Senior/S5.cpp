#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;
vector<vector<ll>> triangle;
ll trianMax(ll f,ll idx){
    ll valMax = triangle[f][idx];
    for(ll i = f+1, trianCounter = 1; i < f+k; i++, trianCounter++){
        for(ll j = 0; j < trianCounter+1; j++){
            valMax = max(valMax,triangle[i][idx+j]);
        }
    }
    return valMax;
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
    ll ans = 0;
    for(ll i = 0; i <= n-k; i++){
        for(ll j = 0; j < i+1; j++){
            ans += trianMax(i,j);
        }
    }
    cout << ans;
    return 0;
}
