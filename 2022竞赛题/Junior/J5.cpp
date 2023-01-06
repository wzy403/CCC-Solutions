#include <bits/stdc++.h>

using namespace std;

int N;
unordered_map<int,vector<int>> n;
bool status = true;

void checker(int m, int r, int c){
    status = true;
    int rb = r-m+1;
    int cb = c-m+1;
    for(int i = rb; i <= r; i++){
        if(n.count(i)){
            for(auto &j : n[i]){
                if(j >= cb && j <= c){
                    status = false;
                    break;
                }
            }
        }
        if(!status){
            if(c+1 <= N){
                checker(m,r,c+1);
            }else if(r+1 <= N){
                checker(m,r+1,m);
            }
            break;
        }
    }
}

int main(){
    cin >> N;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int r,c;
        cin >> r >> c;
        n[r].push_back(c);
    }
    for(int i = N; i > 0; i--){
        checker(i,i,i);
        if(status){
            cout << i;
            return 0;
        }
    }
    return 0;
}
