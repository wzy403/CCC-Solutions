#include <bits/stdc++.h>

using namespace std;

bool myfunction (pair<int,string> i,pair<int,string> j) {
    if(i.first != j.first){
        return (i.first > j.first);
    }

    return (i.second < j.second);
}

int main(){
    int n;
    cin >> n;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        string name;
        cin >> name;
        int r, s , d;
        cin >> r >> s >> d;
        cout << name;
        return 0;
    }
    vector<pair<int,string>> pairs;
    for(int i = 0; i < n; i++){
        pair<int,string> name;
        cin >> name.second;
        int r,s,d;
        cin >> r >> s >> d;
        int temp = 2*r + 3*s + d;
        name.first = temp;
        pairs.push_back(name);
    }
    sort(pairs.begin(), pairs.end(), myfunction);
    cout << pairs[0].second << "\n" << pairs[1].second;
    return 0;
}
