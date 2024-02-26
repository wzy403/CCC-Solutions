#include <bits/stdc++.h>

using namespace std;

vector<int> gate;

int findP(int i){
    if(gate[i] < 0){
        return i;
    }
    int pNew = findP(gate[i]);
    gate[i] = pNew;
    return pNew;
}

bool combine(int a){
    int pa = findP(a);
    if(pa == 0){
        return false;
    }
    int pb = findP(pa-1);

    if(pb <= pa){
        gate[pb] += gate[pa];
        gate[pa] = pb;
    }else{
        gate[pa] += gate[pb];
        gate[pb] = pa;
    }

    return true;
}

int main(){
    int n,g;
    cin >> n >> g;
    gate = vector<int>(n+1,-1);

    bool stop = false;
    int ans = 0;
    for(int i = 0; i < g; i++){
        int p;
        cin >> p;
        if(!stop && combine(p)){
            ans++;
        }else{
            stop = true;
        }
    }


    cout << ans;
    return 0;
}
