#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int answer = 0;
    for(int i = 0; i < n; i++){
        int num1, num2;
        cin >> num1 >> num2;
        num1 *= 5;
        num2 *= 3;
        if(num1 - num2 > 40)
            answer++;
    }
    if(answer == n){
        cout << answer << "+";
        return 0;
    }else{
        cout << answer;
    }
    return 0;
}
