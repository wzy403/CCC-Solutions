#include <bits/stdc++.h>

using namespace std;

int main(){
    int c[4][4];
    int sum = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> c[i][j];
            if(i == 0){
                sum += c[i][j];
            }
        }
    }

    for(int i = 0; i < 4; i++){
        int tempSum = 0;
        for(int j = 0; j < 4; j++){
            tempSum += c[i][j];
        }
        if(tempSum != sum){
            cout << "not magic" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 4; i++){
        int tempSum = 0;
        for(int j = 0; j < 4; j++){
            tempSum += c[j][i];
        }
        if(tempSum != sum){
            cout << "not magic" << endl;
            return 0;
        }
    }

    cout << "magic" << endl;
    return 0;
}
