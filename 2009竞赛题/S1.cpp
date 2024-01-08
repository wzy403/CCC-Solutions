#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll a,b;
    cin >> a >> b;
    int ans = 0;
    int l1 = pow(a,1/6.0);
    int l2 = pow(b,1/6.0);
    for(int i = l1; ; i++){
        ll test = pow(i,6);
        if(test > b){
            break;
        }
        if(test >= a){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
