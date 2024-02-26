#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<string> name;
    unordered_map<string,string> vis;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        name.push_back(a);
    }
    string ans = "good";
    for(int i = 0; i < n; i++){
        string check;
        cin >> check;

        vis[check] = name[i];
        if(vis.count(name[i])){
            if(vis[name[i]] != check){
                ans = "bad";
            }
        }
        if(check == name[i]){
            ans = "bad";
        }
    }
    cout << ans;
    return 0;
}
