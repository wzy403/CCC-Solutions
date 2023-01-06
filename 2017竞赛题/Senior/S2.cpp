#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> r(n);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        r[i] = temp;
    }

    sort(r.begin(),r.end());



    if(n % 2 != 0){
        int half = (int)n/2;

        vector<int> l(half + 1);
        vector<int> h(half);

        for(int i = 0, j = n-1; i < half; i++, j--){
            l[half - i] = r[i];
            h[half - i - 1] = r[j];
        }
        l[0] = r[half];

        for(int i = 0; i < half; i++){
            cout << l[i] << ' ' << h[i] << ' ';
        }
        cout << l[half];
    }else{
        int half = n/2;

        vector<int> l(half);
        vector<int> h(half);

        for(int i = 0, j = n-1; i < half; i++, j--){
            l[half - i - 1] = r[i];
            h[half - i - 1] = r[j];
        }

        for(int i = 0; i < half; i++){
            cout << l[i] << ' ' << h[i] << ' ';
        }
    }
    return 0;
}
