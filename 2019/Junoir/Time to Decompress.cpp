#include <iostream>
#include <string>

using namespace std;

int main(){

    int l;
    cin >> l;
    int num[l];
    string a = "";
    for(int i = 0; i < l; i++){
        cin >> num[i];
        char tempChar;
        cin >> tempChar;
        a += tempChar;
    }

    for(int i = 0; i < l; i++){
        char b = a[i];
        for(int j = 0; j < num[i]; j++){
            cout << b;
        }
        cout << "\n";
    }


    return 0;
}
