#include <iostream>

using namespace std;

int main(){
    int apple = 0, banana = 0;
    for(int i = 3; i > 0; i--){
        int a;
        cin >> a;
        apple += (a*i);
    }

    for(int i = 3; i > 0; i--){
        int a;
        cin >> a;
        banana += (a*i);
    }

    if(apple > banana)
        cout << "A";
    else if(apple == banana)
        cout << "T";
    else
        cout << "B";
    return 0;
}
