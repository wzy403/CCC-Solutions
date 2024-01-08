#include <bits/stdc++.h>

using namespace std;

bool isP(vector<int> &counterN, vector<int> &counterH){
    for(int i = 0; i < 26; i++){
        if(counterN[i] != counterH[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string n,h;
    cin >> n >> h;
    vector<int> counterN(26,0);
    vector<int> counterH(26,0);
    for(int i = 0; i < n.size(); i++){
        counterN[(int)n[i] - 'a']++;
        counterH[(int)h[i] - 'a']++;
    }

    hash<string>to_hash;
    unordered_set<unsigned long long> ans;

    int s = n.size();
    if(isP(counterN,counterH)){
        ans.insert(to_hash(h.substr(0,s)));
    }

    int i = 1, j = n.size();
    while(j < h.size()){
        counterH[(int)h[j] - 'a']++;
        counterH[(int)h[i-1] - 'a']--;
        if(isP(counterN,counterH)){
            ans.insert(to_hash(h.substr(i,s)));
        }
        j++;
        i++;
    }

    cout << ans.size();

    return 0;
}
