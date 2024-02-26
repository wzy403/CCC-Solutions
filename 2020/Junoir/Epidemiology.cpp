#include <iostream>

using namespace std;


int main(){
    int p, n, r;
    cin >> p >> n >> r;

    int total = n;

    int day = 0;

    int Ipeople = n;

    while(total <= p){
        day++;
        Ipeople *= r;
        total += Ipeople;
    }

    cout << day << endl;

    return 0;
}
