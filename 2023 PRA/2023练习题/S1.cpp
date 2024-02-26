#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> p1(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i == 0){
            p1[i] = a;
        }else{
            p1[i] = a + p1[i-1];
        }
    }
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
        if(sum == p1[i]){
            ans = i+1;
        }
    }
    cout << ans;
    return 0;
}
