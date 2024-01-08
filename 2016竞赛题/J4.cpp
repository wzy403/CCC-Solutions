#include <bits/stdc++.h>

using namespace std;

int main(){
    string time;
    cin >> time;

    int HH = (int)(time[0]-'0') * 10 + (time[1]-'0');
    int MM = (int)(time[3]-'0') * 10 + (time[4]-'0');

    double timeLeft = 120;
    while(timeLeft > 0){
        if((HH < 7 || (HH >= 10 && HH < 15) || HH >= 19)){
            timeLeft -= 1;
        }else{
            timeLeft -= 0.5;
        }
        MM++;
        if(MM > 59){
            HH++;
            MM = 0;
            if(HH > 23){
                HH = 0;
            }
        }
    }
    if(HH < 10){
        if(MM < 10){
            cout << "0" << HH << ":" << MM << "0";
        }else{
            cout << "0" << HH << ":" << MM;
        }
    }else{
        if(MM < 10){
            cout << HH << ":" << MM << "0";
        }else{
            cout << HH << ":" << MM;
        }
    }
    return 0;
}
