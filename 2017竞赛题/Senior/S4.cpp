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
    int idx = 0;
    Edge last;
    for(auto &i : edges){
        if(combine(i.n1,i.n2)){
            counter--;
            if(!i.org){
                ans++;
            }
            if(counter == 0){
                idx--;
                last = i;
                break;
            }
            idx++;
        }
    }

    if(last.org && last.weight >= d){
        cout << ans;
        return 0;
    }

    t = vector<int>(n+1, -1);
    for(auto &i : edges){
        if(i.weight < last.weight){
            combine(i.n1,i.n2);
        }else if(i.weight == last.weight){
            if(i.org){
                combine(i.n1,i.n2);
            }
        }else{
            if(i.org){
                if(i.weight <= d){
                    if(combine(i.n1,i.n2)){
                        cout << ans-1;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
