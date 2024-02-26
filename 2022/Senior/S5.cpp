#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
string p;
vector<vector<int>> m;
vector<int> cost;

int dfs(int v, int prev, string s){
    if(p[v-1] == 'Y' || s == "ON"){
        int payCost = INT_MAX;
        int tempCost = cost[v-1];
        bool valid = true;
        for(auto &i : m[v-1]){
            int temp = dfs(i,v,"ON");
            if(temp == INT_MAX){
                valid = !valid;
                break;
            }else{
                tempCost += temp;
            }
        }
        if(valid){
            payCost = tempCost;
        }


        int notPayCost = INT_MAX;
        tempCost = 0;
        valid = true;
        for(auto &i : m[v-1]){
            int temp = dfs(i,v,"normal");
            if(temp == INT_MAX){
                valid = !valid;
                break;
            }else{
                tempCost += temp;
            }
        }
        if(valid){
            notPayCost = tempCost;
        }
        return min(payCost,notPayCost);

    }else{
        int tempCost = INT_MAX;
        int sum = 0;
        for(auto &i : m[v-1]){
            sum += dfs(i,v,"ON");
        }
        for(auto &i : m[v-1]){
            int on = dfs(i,v,"ON");
            int pay = dfs(i,v,"pay");
        }
        return tempCost;
    }
}

int main(){
    int n;
    cin >> n;
    cost.resize(n);
    m.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        m[a-1].push_back(b);
    }
    cin >> p;
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }

    return 0;
}
