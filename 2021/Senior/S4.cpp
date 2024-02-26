#include <bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int>> sideWalk;

int bfs(vector<int> &stations, vector<bool> &vis, int target){

    if(stations[1] == target){
        return 0;
    }

    queue<pair<int,int>> s;
    s.push({stations[1],0});
    vis[stations[1]] = true;

    int index = 2;

    while(!s.empty()){
        pair<int,int> station = s.front();
        s.pop();

        if(sideWalk.count(station.first)){
            vector<int> &temp = sideWalk[station.first];
            for(auto &i : temp){

                if(vis[i]){
                    continue;
                }

                if(i == target){
                    return station.second+1;
                }
                s.push({i,station.second+1});
                vis[i] = true;
            }
        }

        if(stations[index-1] == station.first){
            if(stations[index] == target){
                return index-1;
            }
            s.push({stations[index],index-1});
            vis[stations[index]] = true;
            index++;
        }

    }
    return -1;
}

int main(){
    int n,w,d;
    cin >> n >> w >> d;


    for(int i = 0; i < w; i++){
        int a,b;
        cin >> a >> b;
        sideWalk[a].push_back(b);
    }

    vector<int> stations(n+1);
    for(int i = 1; i <= n; i++){
        cin >> stations[i];
    }

    queue<pair<int,int>> pattern;
    for(int i = 0; i < d; i++){
        int a,b;
        cin >> a >> b;
        pattern.push({a,b});
    }

    for(int i = 0; i < d; i++){
        vector<bool> vis(n+1,false);
        pair<int,int> temp = pattern.front();
        pattern.pop();
        swap(stations[temp.first],stations[temp.second]);

        cout << bfs(stations,vis,n) << "\n";
    }

    return 0;
}
