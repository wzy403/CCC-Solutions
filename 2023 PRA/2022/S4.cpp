#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,c;
    cin >> n >> c;
    vector<int> m(c,0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m[a]++;
    }
    int ans = 0;
    if(c%2==0){
        int half = c/2;
        for(int a = 0; a < half; a++){
            if(m[a] != 0){
                int lim1 = a+half;
                for(int b = a+1; b < lim1; b++){
                    if(m[b] != 0){
                        int lim2 = b-half;
                        cout << a << ' ' <<  b << ' ' << lim2 << endl;
                        for(int c = lim1+1; c < lim2; c--){
                            if(m[c] != 0){
                                ans += (m[a] * m[b] * m[c]);
                            }
                        }
                    }
                }
            }
        }
    }else{
        int half = c/2;
        for(int a = 0; a < half; a++){
            if(m[a] != 0){
                int lim1 = a+half;
                for(int b = a+1; b < lim1; b++){
                    if(m[b] != 0){
                        int lim2 = b+half;
                        for(int c = lim2; c > lim1; c--){
                            if(m[c] != 0){
                                ans += (m[a] * m[b] * m[c]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
