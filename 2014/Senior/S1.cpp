#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int k;
    cin >> k;
    int m;
    cin >> m;
    vector<bool> num(k+1, true);
    for(int i = 0; i < m; i++){
        int r;
        cin >> r;
        int j = 1;
        int counter = 1;
        while(j <= k){
            if(counter == r && num[j]){
                counter = 1;
                num[j] = false;
                j++;
                continue;
            }
            if(num[j]){
                counter++;
            }
            j++;
        }
    }
    for(int i = 1; i <= k; i++){
        if(num[i]){
            cout << i << endl;
        }
    }
    return 0;
}
