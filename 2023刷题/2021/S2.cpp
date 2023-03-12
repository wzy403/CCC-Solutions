#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<bool> N(n+1,false);
    vector<bool> M(m+1,false);
    int k;
    cin >> k;
    int Ccounter = 0, Rcounter = 0;
    for(int i = 0; i < k; i++){
        char a;
        int b;
        cin >> a >> b;
        if(a == 'C'){
            if(M[b]){
                Ccounter--;
            }else{
                Ccounter++;
            }
            M[b] = !M[b];
        }else{
            if(N[b]){
                Rcounter--;
            }else{
                Rcounter++;
            }
            N[b] = !N[b];
        }
    }
    int sum = Ccounter*n + Rcounter*m - 2*Ccounter*Rcounter;
    cout << sum;
    return 0;
}
