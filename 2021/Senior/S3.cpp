#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<ll> p,w,d;

ll calTime(ll pos){
    ll time = 0;

    for(ll i = 0; i < n; i++){

        ll walkD = abs(p[i] - pos);
        if(walkD >= d[i]){
            walkD -= d[i];
            if(walkD < 0){
                walkD = 0;
            }
        }else{
            walkD = 0;
        }
        ll timeTake = walkD * w[i];

        time += timeTake;

    }

    return time;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    p.resize(n);
    w.resize(n);
    d.resize(n);
    ll pMin = 1e18;
    ll pMax = 0;
    for(ll i = 0; i < n; i++){
        cin >> p[i] >> w[i] >> d[i];
        pMin = min(pMin,p[i]);
        pMax = max(pMax,p[i]);
    }

    ll low = pMin, high = pMax;

    while(low <= high){
        ll mid = low + (high-low)/2;

        ll timeM = calTime(mid);
        ll timeL = calTime(mid-1);
        ll timeR = calTime(mid+1);

        if(timeL < timeM && timeR > timeM){
            high = mid-1;
        }else if(timeL > timeM && timeR < timeM){
            low = mid + 1;
        }else if(timeL >= timeM && timeR >= timeM){
            cout << timeM;
            return 0;
        }
    }
    return 0;
}
