#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> m;

void helper(int left, int right){
    while(left >= 0 || right < n){

        if(right < n){
            cout << m[left] << ' ' << m[right] << ' ';
        }else{
            cout << m[left];
        }

        left--;
        right++;

    }
}

int main(){
    cin >> n;
    m.resize(n);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        m[i] = temp;
    }
    sort(m.begin(),m.end());

    if(n % 2){
        helper(n/2,n/2+1);
    }else{
        helper(n/2-1, n/2);
    }

    return 0;
}
