#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == 8 || a == 9){
        if(b == c && (d == 8 || d == 9)){
            cout << "ignore";
        }else{
            cout << "answer";
        }
    }else{
        cout << "answer";
    }
    return 0;
}
