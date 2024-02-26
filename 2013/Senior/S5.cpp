#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= sqrt(i); j++){
            if(i%j == 0){
                int a = i/j;
                int c = a + i;

                if(c <= n){
                    if(dp[c] == -1){
                        dp[c] = dp[i] + j;
                    }else{
                        if(dp[c] > dp[i] + j){
                            dp[c] = dp[i] + j;
                        }
                    }
                }

                c = j + i;

                if(c <= n){
                    if(dp[c] == -1){
                        dp[c] = dp[i] + a;
                    }else{
                        if(dp[c] > dp[i] + a){
                            dp[c] = dp[i] + a;
                        }
                    }
                }
            }
        }
    }

    cout << dp[n];
    return 0;
}
