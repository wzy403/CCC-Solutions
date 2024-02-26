#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> p1(n,0);
    vector<int> p2(n,0);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(i == 0){
            p1[i] = temp;
        }else{
            p1[i] = p1[i-1] + temp;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(i == 0){
            p2[i] = temp;
        }else{
            p2[i] = p2[i-1] + temp;
        }

        if(p1[i] == p2[i]){
            ans = i + 1;
        }
    }

    cout << ans;
    return 0;
}
