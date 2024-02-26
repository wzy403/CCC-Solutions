#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    int n1;
    int n2;
    int cost;
};
bool cmp (const Edge &e1, const Edge &e2){
    return e1.cost < e2.cost;
}
vector<int> t;
int f(int key){
    if(t[key] < 0){
        return key;
    }
    int p = f(t[key]);
    t[key] = p;
    return p;
}
bool combine(int n1, int n2){
    int p1 = f(n1);
    int p2 = f(n2);

    if(p1 == p2){
        return false;
    }

    if(t[p1] <= t[p2]){
        t[p1] += t[p2];
        t[p2] = p1;
    }else{
        t[p2] += t[p1];
        t[p1] = p2;
    }
    return true;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int u,v,l,c;
        cin >> u >> v >> l >> c;
        edges.push_back({u,v,c});
    }

    sort(edges.begin(),edges.end(),cmp);
    int ans = 0;
    int counter = 0;
    for(auto &i : edges){
        if(counter >= n-1){
            break;
        }
        if(combine(i.n1,i.n2)){
            ans += i.cost;
            counter++;
        }
    }
    cout << ans;
    return 0;
}
