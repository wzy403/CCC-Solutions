#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>score(n);
    for(int i = 0; i < n; i++){
        cin >> score[i];
    }
    int answer = 0;
    if(n % k == 0){
        for(int i = 0; i < n; i+=k){
            int tempMaxAns = score[i];
            for(int j = 1; j < k; j++){
                tempMaxAns = max(tempMaxAns,score[i+j]);
            }
            answer += tempMaxAns;
        }
    }else{
        int lim = n%k;
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0] = score[0];
        for(int i = 1; i < k; i++){
            dp[i] = max(dp[i-1],score[i]);
        }
        int d = 2;
        for(int i = k,dc=1; i < n; i++,dc++){
            if(day == k){
                dc = 1;
                d++;
            }
            for(int j = lim; j <= k; j++){
                if(dc % )
            }
        }
        cout << dp[n-1];
        return 0;
    }
    cout << answer;
    return 0;
}
