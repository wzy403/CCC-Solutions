#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    ll n1;
    ll n2;
    ll weight;
};

bool cmp(const Edge &e1, const Edge &e2){
    return e1.weight < e2.weight;
}

vector<ll> t;

ll tFind(ll key){
    if(t[key] < 0){
        return key;
    }
    ll newP = tFind(t[key]);
    t[key] = newP;
    return newP;
}

bool combine(ll n1, ll n2){
    ll p1 = tFind(n1);
    ll p2 = tFind(n2);

    if(p1 == p2){
        return false;
    }

    if(t[p1] <= t[p2]){
        t[p2] += t[p1];
        t[p1] = p2;
    }else{
        t[p1] += t[p2];
        t[p2] = p1;
    }
    return true;
}

int main(){
    ll n,m,p,q;
    cin >> n >> m >> p >> q;
    vector<Edge> edges;
    t = vector<ll> (m*n+1,-1);
    ll energySum = 0;
    for(ll i = 0; i < p; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        for(ll j = 0; j < n; j++){
            edges.push_back({a,b,c});
            a += m;
            b += m;
            energySum += c;
        }
    }

    for(ll i = 0; i < q; i++){
        ll x,y,z;
        cin >> x >> y >> z;
        ll p1 = (x-1)*m;
        ll p2 = (y-1)*m;
        for(ll j = 1; j <= m; j++){
            edges.push_back({j+p1,j+p2,z});
            energySum += z;
        }
    }

    sort(edges.begin(),edges.end(),cmp);

    ll energyNeed = 0;
    ll counter = 0;
    ll lim = m*n - 1;
    for(auto &i : edges){
        if(counter == lim){
            break;
        }
        if(combine(i.n1,i.n2)){
            energyNeed += i.weight;
            counter++;
        }
    }

    cout << energySum - energyNeed;
    return 0;
}
