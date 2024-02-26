#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k, int w){
    vector<int>pins(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pins[i] = a;
    }
    vector<int> sumArr(n+1,0);
    for(int i = 1; i <= n; i++){
        sumArr[i] = sumArr[i-1] + pins[i-1];
    }
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= w; j++){
            dp[i][j] = sumArr[j];
        }
        for(int j = w+1; j <= n; j++){
            dp[i][j] = max(dp[i][j-1], sumArr[j] - sumArr[j-w] + dp[i-1][j-w]);
        }
    }
    return dp[k][n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> ans(t);
    for(int q = 0; q < t; q++){
        int n,k,w;
        cin >> n >> k >> w;
        ans[q] = solve(n,k,w);
    }
    for(auto &i : ans){
        cout << i << "\n";
    }
    return 0;
}
