#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int sum = n;
    for(int i = 0; i < k; i++){
        n *= 10;
        sum += n;
    }
    cout << sum;
    return 0;
}
