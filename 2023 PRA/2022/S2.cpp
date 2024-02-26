#include <bits/stdc++.h>

using namespace std;

unordered_map<string,unordered_set<string>> X;
unordered_map<string,unordered_set<string>> Y;

int check(string t, string b, string c){
    int ans = 0;
    for(auto &together : X[t]){
        if(together != b && together != c){
            ans++;
            X[together].erase(t);
        }
    }
    for(auto &nTogether : Y[t]){
        if(nTogether == b || nTogether == c){
            ans++;
            Y[nTogether].erase(t);
        }
    }
    return ans;
}

int main(){
    int x;
    cin >> x;
    for(int i = 0; i < x; i++){
        string a,b;
        cin >> a >> b;
        X[a].insert(b);
        X[b].insert(a);
    }
    int y;
    cin >> y;
    for(int i = 0; i < y; i++){
        string a,b;
        cin >> a >> b;
        Y[a].insert(b);
        Y[b].insert(a);
    }
    int g;
    cin >> g;
    int ans = 0;
    for(int i = 0; i < g; i++){
        string a,b,c;
        cin >> a >> b >> c;
        ans += check(a,b,c);
        ans += check(b,a,c);
        ans += check(c,a,b);
    }

    cout << ans;

    return 0;
}
