#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    int n;
    cin >> n;
    vector<int> d(n);
    vector<int> p(n);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        d[i] = temp;
    }

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        p[i] = temp;
    }

    sort(d.begin(),d.end());
    if(q == 1){
        sort(p.begin(),p.end());
    }else{
        sort(p.begin(),p.end(),greater<int>());
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += max(d[i],p[i]);
    }

    cout << ans;

    return 0;
}
