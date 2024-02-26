#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    vector<int> counter(4001,0);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            counter[w[i] + w[j]]++;
        }
    }
    return 0;
}
