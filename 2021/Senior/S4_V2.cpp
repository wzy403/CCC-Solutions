#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int,vector<int>> sideWalk;

vector<ll> swHelper(int start){
    vector<ll> s(start+1,1e9);
    vector<bool> vis(start+1,false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    s[start] = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto &i : sideWalk[temp]){
            if(!vis[i]){
                s[i] = s[temp] + 1;
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return s;
}

int main(){
    int n,w,d;
    cin >> n >> w >> d;


    for(int i = 0; i < w; i++){
        int a,b;
        cin >> a >> b;
        sideWalk[b].push_back(a);
    }

    vector<ll> shortcut = swHelper(n);

    vector<int> stations(n+1);
    for(int i = 1; i <= n; i++){
        cin >> stations[i];
    }

    multiset<ll> lowTime;
    for(int i = 1; i <= n; i++){
        int timeNeed = shortcut[stations[i]] + (i-1);
        lowTime.insert(timeNeed);
    }

    queue<pair<int,int>> pattern;
    for(int i = 0; i < d; i++){
        int a,b;
        cin >> a >> b;
        pattern.push({a,b});
    }

    for(int i = 0; i < d; i++){
        pair<int,int> temp = pattern.front();
        pattern.pop();

        int remove1 = shortcut[stations[temp.first]] + temp.first-1;
        int remove2 = shortcut[stations[temp.second]] + temp.second-1;

        auto remove1Index = lowTime.find(remove1);
        lowTime.erase(remove1Index);
        auto remove2Index = lowTime.find(remove2);
        lowTime.erase(remove2Index);

        swap(stations[temp.first],stations[temp.second]);

        lowTime.insert(shortcut[stations[temp.first]] + temp.first-1);
        lowTime.insert(shortcut[stations[temp.second]] + temp.second-1);

        cout << *lowTime.begin() << "\n";
    }

    return 0;
}
