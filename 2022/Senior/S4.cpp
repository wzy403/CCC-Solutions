#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, c;
unordered_map<int,vector<int>> pos;

vector<pair<int,int>> even_helper(int num){
    vector<pair<int,int>> value;
    int lim = num + (c/2);
    for(auto &i : pos){
        if(i.first != num && i.first < lim){
            int lim2 = i.first + (c/2);
            for(auto &j : pos){
                if(j.first > lim && j.first < lim2){
                    value.push_back({i.first,j.first});
                }
            }
        }
    }
    return value;
}

vector<pair<int,int>> odd_helper(int num){
    vector<pair<int,int>> value;
    int lim = num + (c/2);
    for(auto &i : pos){
        if(i.first != num && i.first <= lim){
            int lim2 = i.first + (c/2);
            for(auto &j : pos){
                if(j.first > lim && j.first <= lim2){
                    value.push_back({i.first,j.first});
                }
            }
        }
    }
    return value;
}

int main(){
    //freopen("s4.2-18.in","r",stdin);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int location;
        cin>> location;
        pos[location].push_back(i+1);

    }
    ll answer = 0;
    if(c % 2 == 0){
        for(auto &i : pos){
            vector<pair<int,int>> temp = even_helper(i.first);
            if(temp.size() > 0){
                for(auto &k : temp){
                    answer += (i.second.size() * pos[k.first].size() * pos[k.second].size());
                }
            }
        }
    }else{
        for(auto &i : pos){
            vector<pair<int,int>> temp = odd_helper(i.first);
            if(temp.size() > 0){
                for(auto &k : temp){
                    answer += (i.second.size() * pos[k.first].size() * pos[k.second].size());
                }
            }
        }
    }
    cout << answer;
    return 0;
}
