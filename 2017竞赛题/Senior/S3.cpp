#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>heighs(2001,0);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        heighs[temp]++;
    }

    vector<int> sum (4001,0);

    for(int i = 1; i < 2001; i++){
        sum[i+i] += (int)heighs[i]/2;
        for(int j = i + 1; j < 2001; j++){
            sum[i+j] += min(heighs[i], heighs[j]);
        }
    }

    int counter = 0;
    int longest = 0;
    for(auto &i : sum){
        if(longest < i){
            longest = i;
            counter = 1;
        }else if(i == longest){
            counter++;
        }
    }
    cout << longest << ' ' << counter;
    return 0;
}
