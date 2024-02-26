#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> data(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> data[i][j];
        }
    }
    int startR = 0;
    int startC = 0;
    int startMin = data[0][0];
    if(startMin > data[0][n-1]){
        startR = 0;
        startC = n-1;
        startMin = data[0][n-1];
    }
    if(startMin > data[n-1][0]){
        startR = n-1;
        startC = 0;
        startMin = data[n-1][0];
    }
    if(startMin > data[n-1][n-1]){
        startR = n-1;
        startC = n-1;
        startMin = data[n-1][n-1];
    }
    if(startR == 0){
        if(startC == 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << data[i][j] << ' ';
                }
                cout << "\n";
            }
        }else{
            for(int i = n-1; i >= 0; i--){
                for(int j = 0; j < n; j++){
                    cout << data[j][i] << ' ';
                }
                cout << "\n";
            }
        }
    }else{
        if(startC == 0){
            for(int i = 0; i < n; i++){
                for(int j = n-1; j >= 0; j--){
                    cout << data[j][i] << ' ';
                }
                cout << "\n";
            }
        }else{
            for(int i = n-1; i >= 0; i--){
                for(int j = n-1; j >= 0; j--){
                    cout << data[i][j] << ' ';
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
