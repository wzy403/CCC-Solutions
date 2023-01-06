#include <bits/stdc++.h>

using namespace std;

vector<int> t;

struct Edge{
    int n1;
    int n2;
    int weight;
    bool org;
};

bool cmp(const Edge &e1, const Edge &e2){
    if(e1.weight == e2.weight){
        return e1.org > e2.org;
    }else{
        return e1.weight < e2.weight;
    }
}

int f(int key){
    if(t[key] < 0){
        return key;
    }
    int p = f(t[key]);
    t[key] = p;
    return p;
}

bool combine(int a, int b){
    int pa = f(a);
    int pb = f(b);

    if(pa == pb){
        return false;
    }

    if(t[pa] <= t[pb]){
        t[pb] += t[pa];
        t[pa] = pb;
    }else{
        t[pa] += t[pb];
        t[pb] = pa;
    }
    return true;
}
int main(){
    int n,m,d;
    cin >> n >> m >> d;
    t = vector<int>(n+1, -1);
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(i < n-1){
            edges.push_back({a,b,c,true});
        }else{
            edges.push_back({a,b,c,false});
        }
    }

    sort(edges.begin(),edges.end(),cmp);

    int counter = n-1;
    int ans = 0;
    for(auto &i : edges){
        if(combine(i.n1,i.n2)){
            counter--;
            if(!i.org){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
