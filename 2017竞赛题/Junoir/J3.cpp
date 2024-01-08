#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int t;
    cin >> t;

    int sub = abs(c-a) + abs(d-b);

    if(t - sub < 0){
        cout << "N";
        return 0;
    }

    cout << ((t-sub) % 2 == 0 ? "Y" : "N");
    return 0;
}
