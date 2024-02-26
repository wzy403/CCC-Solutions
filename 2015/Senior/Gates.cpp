#include <iostream>
#include <queue>

using namespace std;

int main(){
    int g,p;
    cin >> g >> p;
    queue<int>airPlan;
    for(int i = 0; i < p; i++){
        int num;
        cin >> num;
        airPlan.push(num);
    }
    int gate = 1;
    while(airPlan.size() > 0 && gate <= g){
        int getNum = airPlan.front();
        if(getNum >= gate){
            gate++;
            airPlan.pop();
        }else{
            gate -= 1;
            break;
        }
    }
    cout << gate;
    return 0;
}
