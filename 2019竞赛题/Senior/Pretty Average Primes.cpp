#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int num){
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0)
            return 0;
    return 1;
}

int main(){
    int t;
    cin >> t;
    int answer[t][2];
    int counter = 0;
    for(int i = 0; i < t; i++){
        int InputNum;
        cin >> InputNum;
        InputNum *= 2;
        int testNum = ((int)InputNum / 6) * 6;
        do{
            int num1 = testNum+1;
            int num2 = InputNum - (testNum+1);
            if(isPrime(num1) && isPrime(num2) && (num1 + num2) == InputNum && num1 > 1 && num2 > 1){
                answer[counter][0] = num1;
                answer[counter][1] = num2;
                counter++;
                break;
            }
            num1 = testNum-1;
            num2 = InputNum - (testNum-1);
            if(isPrime(num1) && isPrime(num2) && (num1 + num2) == InputNum && num1 > 1 && num2 > 1){
                answer[counter][0] = num1;
                answer[counter][1] = num2;
                counter++;
                break;
            }
            int tempNum = (testNum / 6) - 1;
            testNum = 6 * tempNum;
        }while(1);
    }

    for(int i = 0; i < counter; i++)
        cout << answer[i][0] << ' ' << answer[i][1] << "\n";

    return 0;
}
