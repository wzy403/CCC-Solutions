#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int answer = 0;
    if(n % 5 == 0){
        answer++;
    }
    if(n % 4 == 0){
        answer++;
    }
    while(n > 0){
        n -= 5;
        if(n > 0 && n % 4 == 0){
            answer++;
        }
    }
    cout << answer;
    return 0;
}
