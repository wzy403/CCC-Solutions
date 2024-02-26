#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,m,r,c;
    cin >> n >> m >> r >> c;
    vector<vector<char>> ans(n,vector<char>(m,'b'));
    if(r == 0){
        if(c == 0){
            cout << "ab\ncd";
            return 0;
        }else if(c == 1){
            cout << "ab\nac";
            return 0;
        }else if(c == 2){
            cout << "ab\nab";
            return 0;
        }
    }else{
        if(m == 2){
            if((r == 1 && c == 2) || (r == 2 && c == 1)){
                cout << "IMPOSSIBLE";
                return 0;
            }
            if(r == 2 && c == 0){
                cout << "aa\nbb";
                return 0;
            }
            if(r == 2 && c == 2){
                cout << "aa\naa";
                return 0;
            }
            if(r == 1 && c == 0){
                cout << "aa\nbc";
                return 0;
            }
        }
        for(int i = 0; i < r; i++){
            ans[i] = vector<char>(m,'a');
        }
        for(int i = 0; i < c && i < m; i++){
            for(int j = 0; j < n; j++){
                ans[j][i] = 'a';
            }
        }
    }

    for(auto &i : ans){
        for(auto &j : i){
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}
