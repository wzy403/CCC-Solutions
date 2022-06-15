#include <bits/stdc++.h>

using namespace std;
unordered_map<string,unordered_set<string>> togethere;//必须找不到
unordered_map<string,unordered_set<string>> notTogethere; //必须找到

int helper(string temp,unordered_set<string> l){
    int tempCounter = 0;
    if(togethere.count(temp)){
        for(auto &i : l){
            if(togethere[temp].count(i)){
                togethere[i].erase(temp);
                togethere[temp].erase(i);
                tempCounter++;
            }
        }
    }
    if(notTogethere.count(temp)){
        for(auto &i : notTogethere[temp]){
            if(!l.count(i)){
                notTogethere[i].erase(temp);
                tempCounter++;
            }
        }
    }
    return tempCounter;
}

int main(){
    int x;
    cin >> x;

    for(int i = 0; i < x; i++){
        string a,b;
        cin >> a >> b;
        togethere[a].insert(b);
        togethere[b].insert(a);
    }
    int y;
    cin >> y;

    for(int i = 0; i < y; i++){
        string a,b;
        cin >> a >> b;
        notTogethere[a].insert(b);
        notTogethere[b].insert(a);
    }

    int g;
    cin >> g;
    int counter = 0;
    for(int i = 0; i < g; i++){
        string a,b,c;
        cin >> a >> b >> c;
        unordered_set<string> tempSet;
        tempSet.insert(a);
        tempSet.insert(b);
        tempSet.insert(c);
        counter += helper(a,tempSet);
        counter += helper(b,tempSet);
        counter += helper(c,tempSet);
    }

    int sum = x + y;
    cout << sum - counter;
    return 0;
}
