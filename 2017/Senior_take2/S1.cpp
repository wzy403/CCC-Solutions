#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t1(n+1,0);
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        t1[i] = t1[i-1] + temp;
    }
    int t2 = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        t2 += temp;
        if(t2 == t1[i]){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
