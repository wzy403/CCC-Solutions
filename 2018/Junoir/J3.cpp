#include <bits/stdc++.h>

using namespace std;

int main(){
    int d[5];
    for(int i = 1; i <= 4; i++){
        int temp;
        cin >> temp;
        if(i == 1){
            d[0] = temp;
        }
        d[i] = d[i-1] + temp;
    }

    int add = d[0];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < i; j++){
            d[j] += add;
            cout << d[j] << ' ';
        }
        for(int j = i; j < 5; j++){
            d[j] -= add;
            cout << d[j] << ' ';
        }
        cout << "\n";
        if(i < 4){
            add = d[i + 1];
        }
    }

    return 0;
}
