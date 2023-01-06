#include <iostream>

using namespace std;

typedef long long ll;
#define X  1000000001
ll input[3][3];

void fillArr(int i, int j){
    if(i == 0){
        if(input[i+1][j] != X && input[i+2][j] != X){
            input[i][j] = (2*input[i+1][j]) - input[i+2][j];
            return;
        }
        if(j == 0){
            if(input[i][j+1] != X && input[i][j+2] != X){
                input[i][j] = (2*input[i][j+1]) - input[i][j+2];
                return;
            }
        }
        if(j == 1){
            if(input[i][j-1] != X && input[i][j+1] != X){
                input[i][j] = input[i][j-1] + ((input[i][j+1]-input[i][j-1])/2);
                return;
            }
        }
        if(j == 2){
            if(input[i][j-1] != X && input[i][j-2] != X){
                input[i][j] = input[i][j-2] + 2*(input[i][j-1] - input[i][j-2]);
                return;
            }
        }
    }
    if(i == 1){
        if(input[i-1][j] != X && input [i+1][j] != X){
            input[i][j] = input[i-1][j] + ((input[i+1][j]-input[i-1][j])/2);
        }
        if(j == 0){
            if(input[i][j+1] != X && input[i][j+2] != X){
                input[i][j] = (2*input[i][j+1]) - input[i][j+2];
                return;
            }
        }
        if(j == 1){
            if(input[i][j-1] != X && input[i][j+1] != X){
                input[i][j] = input[i][j-1] + ((input[i][j+1]-input[i][j-1])/2);
                return;
            }
        }
        if(j == 2){
            if(input[i][j-1] != X && input[i][j-2] != X){
                input[i][j] = input[i][j-2] + 2*(input[i][j-1] - input[i][j-2]);
                return;
            }
        }
    }

    if(i == 2){
        if(input[i-1][j] != X && input[i-2][j] != X){
            input[i][j] = input[i-2][j] + 2*(input[i-1][j] - input[i-2][j]);
            return;
        }
        if(j == 0){
            if(input[i][j+1] != X && input[i][j+2] != X){
                input[i][j] = (2*input[i][j+1]) - input[i][j+2];
                return;
            }
        }
        if(j == 1){
            if(input[i][j-1] != X && input[i][j+1] != X){
                input[i][j] = input[i][j-1] + ((input[i][j+1]-input[i][j-1])/2);
                return;
            }
        }
        if(j == 2){
            if(input[i][j-1] != X && input[i][j-2] != X){
                input[i][j] = input[i][j-2] + 2*(input[i][j-1] - input[i][j-2]);
                return;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            string a;
            cin >> a;
            if(a == "X")
                input[i][j] = X;
            else
                input[i][j] = stoi(a);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(input[i][j] == X){
                fillArr(i,j);
            }
        }
    }

for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << input[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
