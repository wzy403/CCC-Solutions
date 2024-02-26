#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> h;
//用数组吧每次 l ~ r 的值记下来，这样可以省去重复计算的时间
int helper(int l, int r){
    int tempAns = 0;
    for(int i = l,j = r; i < j; i++,j--){
        tempAns += abs(h[i]-h[j]);
    }
    return tempAns;
}

int main(){
    int n;
    cin >> n;
    h.resize(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        h[i] = temp;
    }
    vector<int> ans(n);
    for(int r = 0; r < n; r++){
        int tempAns = INT_MAX;
        for(int l = 0; r < n; l++){
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
