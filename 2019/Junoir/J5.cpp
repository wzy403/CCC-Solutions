#include <bits/stdc++.h>

using namespace std;
vector<string> rule(3);
vector<string> to(3);
int lim;
string start,result;

int counter;
vector<tuple<int,int,string>> ans;


vector<int> findRule(int key, string & word){
    vector<int> indexs;
    for(int i = 0; i < word.size(); i++){
        if(word.substr(i,rule[key].size()) == rule[key]){
            indexs.push_back(i);
        }
    }
    return indexs;
}

bool dfs(int change, string word){
    if(change == lim && word == result){
        return true;
    }

    if(change < lim){
        for(int i = 0; i < 3; i++){
            vector<int> index = findRule(i,word);
            if(index.size() != 0){
                for(auto& idx : index){
                    string wordNew = word.substr(0,idx) + to[i] + word.substr(idx+rule[i].size());
                    if(dfs(change+1,wordNew)){
                        ans[--counter] = make_tuple(i+1,idx+1,wordNew);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    for(int i = 0; i < 3; i++){
        cin >> rule[i] >> to[i];
    }
    cin >> lim >> start >> result;
    ans.resize(lim);
    counter = lim;

    dfs(0,start);

    for(auto& i : ans){
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << endl;
    }

    return 0;
}
