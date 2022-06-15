#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ,m;
    cin >> n >> m;
    int total = n*8 + m*3;
    if(total == 28){
        cout << 0 << endl;
        return 0;
    }else{
        cout << total%28;
    }
    return 0;
}
