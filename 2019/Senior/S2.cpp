#include <bits/stdc++.h>

using namespace std;

bool isP(int num){
    int l = sqrt(num);
    for(int i = 2; i <= l; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int ave;
        cin >> ave;
        int sum = ave*2;
        if(isP(sum-2)){
            cout << 2 << ' ' << sum-2 << "\n";
            continue;
        }else if(isP(sum-3)){
            cout << 3 << ' ' << sum-3 << "\n";
            continue;
        }
        for(int i = 5; i <= ave; i++){
            if((i-1)%6 == 0 || (i+1)%6 == 0){
                if(isP(i) && isP(sum-i)){
                    cout << i << ' ' << sum-i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
