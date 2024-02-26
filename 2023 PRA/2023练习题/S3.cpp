#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> R(1001,{0,0});
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;
        R[r].first++;
        R[r].second = r;
    }
    sort(R.begin(),R.end(),greater<pair<int,int>>());

    int HF = R[0].first;
    int numMAX = R[0].second;
    int numMIN = R[0].second;
    int fc = 1;
    int SF;
    int pos;
    for(int i = 1; i < n; i++){
        if(HF == R[i].first){
            fc++;
            numMAX = max(numMAX,R[i].second);
            numMIN = min(numMIN,R[i].second);
        }else{
            pos = i;
            SF = R[i].first;
            break;
        }
    }
    if(fc != 1){
        cout << abs(numMAX-numMIN);
        return 0;
    }
    int num1 = R[pos].second;
    int num2 = R[pos].second;
    for(int i = pos; i < n; i++){
        if(SF == R[i].first){
            num1 = max(num1,R[i].second);
            num2 = min(num2,R[i].second);
        }else{
            break;
        }
    }
    int a = abs(numMAX-num1);
    int b = abs(numMAX-num2);
    if(a >= b){
        cout << a;
    }else{
        cout << b;
    }
    return 0;
}
