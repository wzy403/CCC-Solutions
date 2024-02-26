#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int a[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][m];
        }
    }



}

//
//int main(){
//    int m, n;
//    cin >> m >> n;
//
//    int a[n][m];
//
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++){
//            cin >> a[i][m];
//        }
//    }
//
//    int x = m;
//    int y = n;
//
//    int b[1000][2];
//
//    int check = 0;
//
//    for(int x = 0; x < n*m; x++){
//        int temp_num = x*y;
//        int check2 = 0;
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < m; j++){
//                if(a[i][m] == temp_num && check == 0){
//                    b[check][0] = x;
//                    b[check][1] = y;
//                    check++;
////                    x = j;
////                    y = i;
////                    check = 1;
////                    break;
//                }else if(a[i][m] == temp_num){
//                    b[check - 1][0] = x;
//                    b[check - 1][1] = y;
//                    check2++;
//                }else{
//                    check--;
//                }
//            }
//            if(check <= 0 || check2 <= 0){
//                cout << "no" << endl;
//                return 0;
//            }else{
//                x = b[check - 1][0];
//                y = b[check - 1][1];
//            }
//        }
//
//        if(x == 0 && y == 0){
//            cout << "yes" << endl;
//            return 0;
//        }
//
//    }
//
//
//    return 0;
//}
//
