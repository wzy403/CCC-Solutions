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

ll tFind(vector<ll> &t, ll key){
    if(t[key] < 0){
        return key;
    }
    ll newP = tFind(t,t[key]);
    t[key] = newP;
    return newP;
}

bool combine(vector<ll> &t,ll n1, ll n2){
    ll p1 = tFind(t,n1);
    ll p2 = tFind(t,n2);

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
    vector<Edge> planets;
    vector<Edge> cities;
    ll energyTotal = 0;
    for(int i = 0; i < p; i++){
        int a,b,c;
        cin >> a >> b >> c;
        cities.push_back({a,b,c});
        energyTotal += (c * n);
    }
    for(int i = 0; i < q; i++){
        int x,y,z;
        cin >> x >> y >> z;
        planets.push_back({x,y,z});
        energyTotal += (z * m);
    }

    sort(planets.begin(),planets.end(),cmp);
    sort(cities.begin(),cities.end(),cmp);

    int pCounter = n;
    int cCounter = m;

    vector<ll> pTree(n+1,-1);
    vector<ll> cTree(m+1,-1);

    ll energyNeed = 0;
    int cIdx = 0, pIdx = 0;
    while(pCounter > 1 || cCounter > 1){
        if(pCounter > 1 && cCounter > 1){

            Edge pe = planets[pIdx];
            Edge ce = cities[cIdx];

            if(pIdx < planets.size() && cIdx < cities.size()){
                Edge pe = planets[pIdx];
                Edge ce = cities[cIdx];
                if(pe.weight >= ce.weight){
                    if(combine(cTree,ce.n1,ce.n2)){
                        cCounter--;
                        energyNeed += (ce.weight * pCounter);
                    }
                    cIdx++;
                }else{
                    if(combine(pTree,pe.n1,pe.n2)){
                        pCounter--;
                        energyNeed += (pe.weight * cCounter);
                    }
                    pIdx++;
                }
            }else if(cIdx < cities.size()){
                Edge ce = cities[cIdx];

                if(combine(cTree,ce.n1,ce.n2)){
                    energyNeed += (ce.weight * pCounter);
                    cCounter--;
                }
                cIdx++;
            }else{
                Edge pe = planets[pIdx];

                if(combine(pTree,pe.n1,pe.n2)){
                    energyNeed += (pe.weight * cCounter);
                    pCounter--;
                }
                pIdx++;
            }
        }else if(cCounter > 1){
            Edge ce = cities[cIdx];

            if(combine(cTree,ce.n1,ce.n2)){
                energyNeed += ce.weight;
                cCounter--;
            }
            cIdx++;
        }else{
            Edge pe = planets[pIdx];

            if(combine(pTree,pe.n1,pe.n2)){
                energyNeed += pe.weight;
                pCounter--;
            }
            pIdx++;
        }

    }
    cout << energyTotal - energyNeed;
    return 0;
}
