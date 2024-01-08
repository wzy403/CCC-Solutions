#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    unordered_map<int,vector<int>> mp;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    string stauts;
    cin >> stauts;
    vector<bool> p(n+1);
    for(int i = 1; i <= n; i++){
        char temp = stauts[i-1];
        p[i] = (temp == 'Y' ? true : false);
    }

    vector<int> cost(n+1);
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }


    return 0;
}
