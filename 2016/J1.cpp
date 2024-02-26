#include <bits/stdc++.h>

using namespace std;

int main(){
    int counter = 0;
    for(int i = 0; i < 6; i++){
        char a;
        cin >> a;
        if(a == 'W'){
            counter++;
        }
    }

    if(counter >= 5){
        cout << 1;
    }else if(counter >= 3){
        cout << 2;
    }else if(counter >= 1){
        cout << 3;
    }else{
        cout << -1;
    }
    return 0;
}
