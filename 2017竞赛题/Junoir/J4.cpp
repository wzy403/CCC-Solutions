#include <bits/stdc++.h>

using namespace std;

int main(){
    int D;
    cin >> D;

    int total = 2;
    for(int i = 1; i < 10; i++){
        int temp = 0;
        if(i < 6){
            temp++;
        }
        for(int j = 1; j < 12; j++){
            int a = i + j;
            int b = a + j;
            if(a < 6 && b < 10){
                temp++;
            }

            int c = i-j;
            int d = c-j;
            if(c >= 0 && c < 6 && d < 10 && d >= 0){
                temp++;
            }
        }
        total += temp;
    }

    int ans = (D/720)*total;

    int n = D%720;

    int a=1,b=2,c=0,d=0;
    while(n > 0){
        d++;
        if(d > 9){
            c++;
            d = 0;
        }

        if(c > 5){
            b++;
            c = 0;
        }

        if(b > 9){
            b = 0;
            a++;
        }

        if(a == 1 && b > 2){
            a = 0;
            b = 1;
        }

        if(a == 0 && (b-c == c-d)){
            ans++;
        }else if(a != 0 && (a-b == b-c && b-c == c-d)){
            ans++;
        }
        n--;
    }

    cout << ans;
    return 0;
}
