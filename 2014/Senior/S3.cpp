#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    vector<char> ans(t);
    for(int q = 0; q < t; q++){
        int n;
        cin >> n;
        stack<int> m;
        for(int i = 0; i < n; i++){
            int car;
            cin >> car;
            m.push(car);
        }
        stack<int> branch;
        int pos = 0;
        while(!m.empty()){
            int car = m.top();
            if(car - 1 != pos){
                if(!branch.empty()){
                    int carB = branch.top();
                    if(carB - 1 == pos){
                        pos++;
                        branch.pop();
                        continue;
                    }
                }
                branch.push(car);
            }else{
                pos++;
            }
            m.pop();
        }
        char tempAns = 'Y';
        while(!branch.empty()){
            int car = branch.top();
            branch.pop();
            if(car - 1 != pos){
                tempAns = 'N';
                break;
            }else{
                pos++;
            }
        }
        ans[q] = tempAns;
    }
    for(auto &i : ans){
        cout << i << "\n";
    }
    return 0;
}
