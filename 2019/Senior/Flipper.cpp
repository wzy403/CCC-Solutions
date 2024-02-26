#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin >> a;
    int Hcount = 0, Vcount = 0;
    for(int i = 0; i < a.length(); i++){
        switch(a[i]){
            case 'H':
                Hcount++;
                break;
            case 'V':
                Vcount++;
                break;
        }
    }

    if(Hcount % 2 == 0 && Vcount % 2 == 0)
        cout << "1 2\n3 4";
    else if(Hcount % 2 == 1 && Vcount % 2 == 1)
        cout << "4 3\n2 1";
    else if(Hcount % 2 == 1 && Vcount % 2 == 0)
        cout << "3 4\n1 2";
    else
        cout << "2 1\n4 3";

    return 0;
}
