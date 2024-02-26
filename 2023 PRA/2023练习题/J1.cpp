#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int counter = 0;
    if(n > 5){
        counter = n-5;
        n -= counter;
    }
    while(counter <= n){
        ans++;
        n--;
        counter++;
    }
    cout << ans;
    return 0;
}
