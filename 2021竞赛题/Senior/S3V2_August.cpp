#include <bits/stdc++.h>
using namespace std;
long long num;
long long *p, *w, *d;

long long timeAll(long long c){
    long long time = 0;
    for(int i = 0; i < num ; i++){
        long long wd = abs(c - p[i]);

        if(wd > d[i]){
            wd = wd-d[i];
            if(wd < 0){
                wd = 0;
            }
        }else{
            wd = 0;
        }
        time += w[i] * wd;
    }
    return time;
}

int main(){
    cin >> num;
    p = new long long[num];
    w = new long long[num];
    d = new long long[num];
    long long minP = 1000000000,
        maxP = 0;
    for(int i = 0; i < num; i++){
        cin >> p[i] >> w[i] >> d[i];
        minP = min(minP,p[i]);
        maxP = max(maxP,p[i]);
    }

    long long ans = 1e18;
    long long target = (maxP - minP) /3;
    if(target == 0){
        ans = 0;
    }
    while(target != 0){

        long long l = minP+target, r = maxP-target;

        long long lt = timeAll(l);
        long long rt = timeAll(r);

        ans = min(ans,lt);
        ans = min(ans,rt);

        if(lt > rt){
            minP = l;
        }else if(lt < rt){
            maxP = r;
        }else{
            break;
        }
        target = (maxP - minP) / 3;
    }

    cout << ans;

    delete[] p,w,d;
    return 0;
}
