#include <bits/stdc++.h>

using namespace std;

int main(){
    string c;
    cin >> c;
    int hCount = 0;
    int vCount = 0;
    for(auto &i : c){
        if(i == 'H'){
            hCount = !hCount;
        }else{
            vCount = !vCount;
        }
    }

    if(hCount == 0){
        if(vCount == 0){
            cout << "1 2\n3 4";
        }else{
            cout << "2 1\n4 3";
        }
    }else{
        if(vCount == 0){
            cout << "3 4\n1 2";
        }else{
            cout << "4 3\n2 1";
        }
    }
    return 0;
}
