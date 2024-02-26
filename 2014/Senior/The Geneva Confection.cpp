#include <iostream>
#include <stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    string answer = "";
    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        stack<int>carOrder;
        for(int i = 0; i < n; i++){
            int car;
            cin >> car;
            carOrder.push(car);
        }
        stack<int>branch;

        int order = 1;
        while(true){
            if(order == n){
                answer += "Y\n";
                break;
            }
            int getCar;
            if(!carOrder.empty()){
                getCar = carOrder.top();
            }
            if(getCar != order || carOrder.empty()){
                if(!branch.empty()){
                    int branchCar = branch.top();
                    if(branchCar == order){
                        branch.pop();
                        order++;
                        continue;
                    }
                }
                if(carOrder.empty() && branch.top() != order){
                    answer += "N\n";
                    break;
                }
                branch.push(getCar);
                carOrder.pop();
            }else{
                order++;
                carOrder.pop();
            }
        }
    }
    cout << answer;
    return 0;
}
