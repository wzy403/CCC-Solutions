#include <iostream>
#include <algorithm>

using namespace std;

int check(int l, int w, int h, int Il, int Iw, int Ih){
    if(l >= Il && w >= Iw && h >= Ih){
        return 1;
    }else if(l >= Il && w >= Ih && h >= Iw){
        return 1;
    }else if(l >= Ih && w >= Il && h >= Iw){
        return 1;
    }else if(l >= Ih && w >= Il && h >= Iw){
        return 1;
    }else if(l >= Ih && w >= Iw && h >= Il){
        return 1;
    }else if(l >= Iw && w >= Ih && h >= Il){
        return 1;
    }else if(l >= Iw && w >= Il && h >= Ih){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    int box[n];
    int pos[n];
    for(int i = 0; i < n; i++){
        pos[i] = i;
    }
    int sizeBox[n][3];
    for(int i = 0; i < n; i++){
        int l, w, h;
        cin >> l >> w >> h;
        box[i] = l*w*h;
        sizeBox[i][0] = l;
        sizeBox[i][1] = w;
        sizeBox[i][2] = h;
    }
    for(int i = 1; i < n; i++){
        int key = box[i];
        int TempPos = pos[i];
        int j = i - 1;
        while(j >= 0 && key < box[j]){
            box[j+1] = box[j];
            pos[j+1] = pos[j];
            j--;
        }
        box[j+1] = key;
        pos[j+1] = TempPos;
    }

    int m;
    cin >> m;
    int ItemBox[m][3];
    for(int i = 0; i < m; i++){
        int l, w, h;
        cin >> l >> w >> h;
        ItemBox[i][0] = l;
        ItemBox[i][1] = w;
        ItemBox[i][2] = h;
    }

    for(int i = 0; i < m; i++){
        int noFind = 0;
        for(int j = 0; j < n; j++){
        int p = pos[j];

        int l = sizeBox[p][0];
        int w = sizeBox[p][1];
        int h = sizeBox[p][2];
        int Il = ItemBox[i][0];
        int Iw = ItemBox[i][1];
        int Ih = ItemBox[i][2];
            if(check(l,w,h,Il,Iw,Ih) == 1){
                cout << box[j] << endl;
                noFind = 1;
                break;
            }
        }
        if(noFind == 0){
            cout << "Item does not fit." << endl;
        }
    }

    return 0;
}
