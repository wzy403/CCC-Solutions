#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> h;
vector<vector<int>> diff;
int helper(int l, int r){
    int tempAns = 0;
    for(int i = l,j = r; i < j; i++,j--){
        if(diff[i][j] != -1){
            tempAns += diff[i][j];
            break;
        }
        tempAns += abs(h[i]-h[j]);
    }
    diff[l][r] = tempAns;
    return tempAns;
}

int main(){
    int n;
    cin >> n;
    h.resize(n);
    diff = vector<vector<int>> (n,vector<int>(n,-1));
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        h[i] = temp;
    }
    vector<int> ans(n);
    for(int r = 0; r < n; r++){
        int tempAns = INT_MAX;
        for(int l = 0; l < n; l++){
            if(r + l >= n || tempAns == 0){
                break;
            }
            tempAns = min(tempAns,helper(l,l+r));
        }
        ans[r] = tempAns;
    }
    for(auto &i : ans){
        cout << i << ' ';
    }
    return 0;
}
