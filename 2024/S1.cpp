#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int half = n / 2;
    vector<int> hat(n);
    for(int i = 0; i < n; i++){
        cin >> hat[i];
    }
    int ans = 0;
    for(int i = 0; i < half; i++){
        if(hat[i] == hat[i+half]){
            ans += 2;
        }
    }
    cout << ans;
    return 0;
}
