#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n,m;
    cin >> k >> n >> m;
    vector<vector<pair<int,int>>> gragh(n+1);
    for(int i = 0; i < m; i++){
        int a,b,t,h;
        cin >> a >> b >> t >> h;
        if(h < 1){
            gragh[a].push_back({b,t});
            gragh[b].push_back({a,t});
        }
    }
    int A,B;
    cin >> A >> B;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> cost(n+1,INT_MAX);
    vector<bool> vis(n+1);
    pq.push({0,A});
    cost[A] = 0;
    vis[A] = true;
/*
5 7
1 5 0 7
1 2 0 1
2 5 0 3
3 4 0 1
2 3 0 1
2 4 0 5
1 4 0 1*/
    while(!pq.empty()){
        int start = pq.top().second;
        int tempCost = pq.top().first;
        pq.pop();

        for(auto &i : gragh[start]){
            if(vis[i.first]){
                continue;
            }
            if(tempCost + i.second < cost[i.first]){
                cost[i.first] = tempCost + i.second;
                pq.push({cost[i.first],i.first});
            }
        }
    }

    cout << (cost[B] != INT_MAX ? cost[B] : -1);

    return 0;
}
