#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isP(int key){
    for(int i = 2; i <= sqrt(key); i++){
        if(key % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    vector<int> number(t);
    int fMax = 0;
    for(int i = 0; i < t; i++){
        int a;
        cin >> a;
        fMax = max(fMax,a);
        number[i] = a;
    }

    unordered_set<int> f;
    f.insert(1);
    int first = 1;
    int last = 1;
    while(last <= fMax){
        int temp = last;
        last = first + last;
        f.insert(last);
        first = temp;
    }

    for(auto &i : number){
        if(!isP(i) && f.count(i)){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}
