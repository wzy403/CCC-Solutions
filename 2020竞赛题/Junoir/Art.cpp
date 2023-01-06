#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n][2];

    string temp_str = "";

    int max_X = 0, min_X = 1e18;
    int max_Y = 0, min_Y = 1e18;

    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        for(int j = 0; j < a.length(); j++){
            if(a[j] == ','){
                arr[i][0] = stoi(temp_str);
                max_X = max(max_X, arr[i][0]);
                min_X = min(min_X, arr[i][0]);
                temp_str = "";
                continue;
            }
            temp_str += a[j];
        }
        arr[i][1] = stoi(temp_str);
        max_Y = max(max_Y, arr[i][1]);
        min_Y = min(min_Y, arr[i][1]);
        temp_str = "";
    }

    cout << min_X-1 << "," << min_Y-1 << endl;
    cout << max_X+1 << "," << max_Y+1 << endl;

    return 0;
}
