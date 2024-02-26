#include <bits/stdc++.h>

using namespace std;

int main(){
    int r,s;
    cin >> r >> s;
    int total = r*8 + s*3;
    if(total > 28){
        cout << total-28;
        return 0;
    }
    cout << (total%28);
    return 0;
}
