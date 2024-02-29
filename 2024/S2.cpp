#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char solve(){
    string s;
    cin >> s;
    unordered_map<char,int> counter;
    for(auto &c : s){
        counter[c]++;
    }

    bool ans = true;
    bool lastIsHeavy = (counter[s[0]] > 1 ? true : false);
    for(int i = 1; i < s.size(); i++){
        if((!lastIsHeavy && counter[s[i]] == 1) || (lastIsHeavy && counter[s[i]] > 1)){
            ans = false;
            break;
        }
        lastIsHeavy = !lastIsHeavy;
    }
    return (ans ? 'T' : 'F');
}

int main(){
    int t, n;
    cin >> t >> n;
    for(int i = 0; i < t; i++){
        cout << solve() << "\n";
    }
    return 0;
}
