#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n+1);
    for(int i = 0; i <= n; i++){
        int a;
        cin >> a;
        h[i] = a;
    }
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        w[i] = a;
    }
    double ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (h[i]+h[i-1]) * w[i-1] / 2.0;
    }
    printf("%.1lf",ans);
    return 0;
}
