#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string,string> b;
    for(int i = 0; i < n; i++){
        string c;
        cin >> c;
        string num;
        cin >> num;
        if(!b.count(num)){
            b[num] = c;
        }
    }
    string s;
    cin >> s;
    int i = 0;
    while(i < s.length()){
        for(int j = 1; j <= s.length(); j++){
            string temp = s.substr(i,j);
            if(b.count(temp)){
                cout << b[temp];
                i += temp.length();
                break;
            }
        }
    }
    return 0;
}
