#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,0);

    dp[1] = 0;
    dp[2] = 1;
    for(int i = 2; i <= n; i++){
        for(int a = 1; a <= sqrt(i); a++){
            if(i % a == 0){
                int c = i+a;
                int b = i/a;

                if(c <= n){
                    if(dp[i] + b < dp[c]){
                        dp[c] = dp[i] + b;
                    }else if(dp[c] == 0){
                        dp[c] = dp[i] + b;
                    }
                }

                c = i+b;
                if(c <= n){
                    if(dp[i] + a < dp[c]){
                        dp[c] = dp[i] + a;
                    }else if(dp[c] == 0){
                        dp[c] = dp[i] + a;
                    }
                }
            }
        }
    }
    cout << dp[n];
    return 0;
}
