#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    if(x < 0){
        if(y > 0){
            cout << 2;
        }else{
            cout << 3;
        }
    }else{
        if(y > 0){
            cout << 1;
        }else{
            cout << 4;
        }
    }
    return 0;
}
