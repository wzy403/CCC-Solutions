#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 'C' && a[i] == b[i]){
            answer++;
        }
    }
    cout << answer;
    return 0;
}
