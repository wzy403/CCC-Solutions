#include <bits/stdc++.h>

using namespace std;

int main(){
//    freopen("s3.3-45.in","r",stdin);
//    freopen("test.txt", "w", stdout);
    long long n, m, k;
    cin >> n >> m >> k;

    long long *answer = new long long[n];

    long long i;

    for(i = 0; i < n; i++){
        long long cur = k - (n - i - 1);
        cur = min(cur,m);
        if(cur <= 0){
            break;
        }
        if(i+1 <= cur){
            answer[i] = i+1;
            k -= (i + 1);
        }else{
            answer[i] = answer[i-cur];
            k -= cur;
        }
    }

    if(k != 0 || i != n){
        cout << "-1";
        return 0;
    }
    for(int j = 0; j < n; j++){
        cout << answer[j] << ' ';
    }
    delete[] answer;
    return 0;
}
