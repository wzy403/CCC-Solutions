#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    double answer = INT_MAX;
    for(int i = 1; i < n-1; i++){
        answer = min(answer,(num[i+1]-num[i-1])/2.0);
    }
    printf("%.1lf", answer);
    return 0;
}
