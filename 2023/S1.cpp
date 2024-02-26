#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int c;
    cin >> c;
    vector<int> up(c);
    for(int i = 0; i < c; i++){
        int b;
        cin >> b;
        up[i] = b;
    }

    vector<int> down(c);
    for(int i = 0; i < c; i++){
        int b;
        cin >> b;
        down[i] = b;
    }

    int ans = 0;
    bool isTouchUP = false;
    bool isTouchDown = false;

    for(int i = 0; i < c; i++){
        if(up[i] == 1){
            if(!isTouchUP){
                isTouchUP = true;
                ans += 3;
            }else{
                ans += 1;
            }
        }else{
            isTouchUP = false;
        }
        if(down[i] == 1){
            if(!isTouchDown){
                if(up[i] != 1 || i % 2 == 1){
                    ans += 3;
                }else{
                    ans += 1;
                }
                isTouchDown = true;
            }else{
                if(up[i] != 1){
                    ans += 1;
                }else{
                    if(i % 2 == 0){
                        ans -= 1;
                    }else{
                        ans += 1;
                    }
                }
            }
        }else{
            isTouchDown = false;
        }
    }
    cout << ans;
    return 0;
}
