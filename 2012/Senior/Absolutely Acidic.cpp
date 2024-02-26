#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int NumCounter[1001] = {0};
    int NumIndex[1001];
    for(int i = 0; i < 1001; i++){
        NumIndex[i] = i;
    }
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;
        NumCounter[r]++;
    }
    for(int i = 1; i < 1001; i++){
        int key = NumCounter[i];
        int index = NumIndex[i];
        int j = i - 1;
        while(j >= 0 && key > NumCounter[j]){
            NumCounter[j + 1] = NumCounter[j];
            NumIndex[j + 1] = NumIndex[j];
            j--;
        }
        NumCounter[j + 1] = key;
        NumIndex[j + 1] = index;
    }
    if(NumCounter[0] == NumCounter[1]){
        int Counter = NumCounter[0];
        int i = 2;
        while(NumCounter[i] == Counter && i < n){
            i++;
        }
        sort(NumIndex,NumIndex+i);
        cout << abs(NumIndex[0] - NumIndex[i-1]);
        return 0;
    }else{
        int Counter = NumCounter[1];
        int i = 2;
        while(NumCounter[i] == Counter && i < n){
            i++;
        }
        sort(NumIndex+1,NumIndex+i);
        int num1 = abs(NumIndex[0] - NumIndex[i-1]);
        int num2 = abs(NumIndex[0] - NumIndex[1]);
        int answer = num1 > num2 ? num1:num2;
        cout << answer;
        return 0;
    }


    return 0;
}
