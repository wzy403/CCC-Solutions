#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int s[n];
    int answer = 0;
    for(int i = 0; i < 2;i++){
        int total = 0;
        for(int j = 0; j < n; j++){
            int num;
            if(i == 0){
                cin >> num;
                total += num;
                s[j] = total;
            }else{
                cin >>  num;
                total += num;
                if(total == s[j]){
                    answer = j+1;
                }
            }
        }
    }
    cout << answer;
    return 0;
}
