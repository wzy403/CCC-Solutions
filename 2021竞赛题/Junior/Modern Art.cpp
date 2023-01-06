#include <iostream>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int k;
    cin >> k;

    int arrR[m] = {0}, arrC[n] = {0};

    int countR = 0;
    int countC = 0;

    for(int i = 0; i < k; i++){
        string a;
        cin >> a;
        if(a == "R"){
            int num;
            cin >> num;
            if(arrR[num-1] == 0){
                arrR[num-1] = 1;
                countR++;
            }else{
                arrR[num-1] = 0;
                countR--;
            }
        }else{
            int num;
            cin >> num;
            if(arrC[num-1] == 0){
                arrC[num-1] = 1;
                countC++;
            }else{
                arrC[num-1] = 0;
                countC--;
            }
        }
    }

    int sum = countR * n + (countC * m - (2*countC*countR));

    cout << sum << endl;

    return 0;
}
