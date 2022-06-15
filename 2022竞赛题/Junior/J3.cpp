#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >> n;
    vector<string>answer;
    int checker = 0;
    string temp = "";
    for(auto &i : n){
        if(i >= 'A' && i <= 'Z' && checker == 0){
            temp += i;
            continue;
        }
        if(i == '+'){
            checker = 1;
            temp += " tighten ";
            continue;
        }else if(i == '-'){
            checker = 1;
            temp += " loosen ";
            continue;
        }
        if(i >= '0' && i <= '9' && checker == 1){
            temp += i;
            continue;
        }
        if(checker == 1 && i >= 'A' && i <= 'Z'){
            answer.push_back(temp);
            temp = "";
            temp += i;
            checker = 0;
        }
    }
    answer.push_back(temp);
    for(auto &i : answer){
        cout << i << endl;
    }
    return 0;
}

