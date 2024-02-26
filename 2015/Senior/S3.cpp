#include <bits/stdc++.h>

using namespace std;

vector<bool>gate;

bool helper(int g){
    for(int i = g-1; i >= 0; i--){
        if(!gate[i]){
            gate[i] = !gate[i];
            return true;
        }
    }
    return false;
}

int main(){
    int g,p;
    cin >> g >> p;
    gate.resize(g);
    bool check = true;
    int ans = 0;
    for(int i = 0; i < p; i++){
        int plane;
        cin >> plane;
        if(!check){
            continue;
        }
        if(!helper(plane)){
            check = false;
        }else{
            ans++;
        }
    }
    cout << ans;
    return 0;
}
