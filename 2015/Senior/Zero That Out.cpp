#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k;
    cin >> k;
    stack<int>s;
    for(int i = 0; i < k; i++){
        int n;
        cin>> n;
        s.push(n);
    }

    int ZeroCounter = 0;
    int answer = 0;
    while(s.size() > 0){
        int getNum = s.top();
        if(getNum == 0){
            s.pop();
            ZeroCounter++;
        }else{
            if(ZeroCounter != 0){
                s.pop();
                ZeroCounter--;
            }else{
                answer += getNum;
                s.pop();
            }
        }
    }

    cout << answer;
    return 0;
}
