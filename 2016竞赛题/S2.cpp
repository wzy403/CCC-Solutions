#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int q1(){
    cin >> n;
    vector<int> d(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        d[i] = a;
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        p[i] = a;
    }
    sort(d.begin(),d.end());
    sort(p.begin(),p.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += max(d[i],p[i]);
    }
    return ans;
}

int q2(){
    cin >> n;
    vector<int> d(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        d[i] = a;
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        p[i] = a;
    }
    sort(d.begin(),d.end());
    sort(p.begin(),p.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += max(d[i],p[n-1-i]);
    }
    return ans;
}

int main(){
    int q;
    cin >> q;
    if(q == 1){
        cout << q1();
    }else{
        cout << q2();
    }
    return 0;
}
