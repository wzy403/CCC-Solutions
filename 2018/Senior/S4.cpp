#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll,ll> dp;

ll f(ll n){
    if(n == 1 || n == 2){
        return 1;
    }
    if(dp.count(n)){
        return dp[n];
    }

    ll ans = 0;
    ll x = n;
    while(x >= 2){
        ll w = n/x;
        ll y = n/(w+1);

        ans += (x-y) * f(w);
        x = y;
    }
    return dp[n] = ans;
}

int main(){
    ll n;
    cin >> n;

    cout << f(n);
    return 0;
}
