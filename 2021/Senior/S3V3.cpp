#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<ll> p,w,d;

ll sumTime(ll pos){
    ll timeTake = 0;
    for(int j = 0; j < n; j++){
        ll dis = 0;
        if(p[j]-d[j] > pos){
            dis = p[j] - d[j] - pos;
        }else if(p[j] + d[j] < pos){
            dis = pos - p[j] - d[j];
        }
        timeTake += dis * w[j];
    }
    return timeTake;
}

int main(){
    cin >> n;
    p.resize(n);
    w.resize(n);
    d.resize(n);
    ll low = 1e18, high = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i] >> w[i] >> d[i];
        low = min(low,p[i]);
        high = max(high,p[i]);
    }
    while(low <= high){
        ll mid = low + (high-low) / 2;
        ll midTime = sumTime(mid);
        ll midR = sumTime(mid+1);
        ll midL = sumTime(mid-1);
        if(midL >= midTime && midR >= midTime){
            cout << midTime;
            return 0;
        }else if(midL > midTime && midR < midTime){
            low = mid -1;
        }else if(midL < midTime && midR > midTime){
            high = mid+1;
        }
    }
    return 0;
}
