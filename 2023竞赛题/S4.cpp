#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    int n1;
    int n2;
    ll weight;
};

bool cmp(const Edge &e1, const Edge &e2){
    return e1.weight < e2.weight;
}

vector<int> trees;

int uFind(int key){
    if(trees[key] < 0){
        return key;
    }
    int p = uFind(trees[key]);
    trees[key] = p;
    return p;
}

bool combine(int n1, int n2){
    int p1 = uFind(n1);
    int p2 = uFind(n2);
    if(p1 == p2){
        return false;
    }
    if(trees[p1] <= trees[p2]){
        trees[p1] += trees[p2];
        trees[p2] = p1;
    }else{
        trees[p2] += trees[p1];
        trees[p1] = p2;
    }
    return true;
}

int main(){
    int n,m;
    cin >> n >> m;
    trees = vector<int>(n+1,-1);
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int u,v,l,c;
        cin >> u >> v >> l >> c;
        edges.push_back({u,v,(ll)c});
    }
    sort(edges.begin(),edges.end(),cmp);

    int counter = 0;
    ll ans = 0;
    for(auto &i : edges){
        if(counter >= n-1){
            break;
        }
        int n1 = i.n1;
        int n2 = i.n2;
        if(combine(n1,n2)){
            ans += i.weight;
            counter++;
        }
    }
    cout << ans;

    return 0;
}
