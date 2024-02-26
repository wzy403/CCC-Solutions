#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> r(n);
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    sort(r.begin(),r.end());

    int lim = n/2;
    vector<pair<int,int>> ans;
    if(n % 2 == 0){
        for(int i = 0; i < lim; i++){
            ans.push_back({r[i],r[n-i-1]});
        }
        for(int i = ans.size()-1; i >= 0; i--){
            cout << ans[i].first << ' ' << ans[i].second << ' ';
        }
    }else{
        for(int i = 1; i <= lim; i++){
            ans.push_back({r[i],r[n-i]});
        }
        for(int i = ans.size()-1; i >= 0; i--){
            cout << ans[i].first << ' ' << ans[i].second << ' ';
        }
        cout << r[0];
    }
    return 0;
}
