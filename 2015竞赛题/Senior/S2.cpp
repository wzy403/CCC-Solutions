#include <bits/stdc++.h>

using namespace std;

int main(){
    int j,a;
    cin >> j >> a;
    char jersy[j];
    for(int i = 0; i < j; i++){
        cin >> jersy[i];
    }

    int ans = 0;
    for(int i = 0; i < a; i++){
        char needSize;
        int number;
        cin >> needSize >> number;
        if(jersy[number-1] <= needSize){
            jersy[number-1] = 'T';
            ans++;
        }
    }
    cout << ans;
    return 0;
}
