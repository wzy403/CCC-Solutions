#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m[n][n] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = 0;
        }
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int r, c;
        cin >> r >> c;
        m[r][c] = 1;
    }

    return 0;
}
