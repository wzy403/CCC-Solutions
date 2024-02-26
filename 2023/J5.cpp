#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> vis;
string word;
int r,c;

bool L(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }
    if(j - 1 >= 0){
        if(L(i,j-1,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool R(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }

    if(j + 1 < c){
        if(R(i,j+1,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool Up(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }
    if(i - 1 >= 0){
        if(Up(i-1,j,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool Down(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }

    if(i + 1 < r){
        if(Down(i+1,j,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool Rup(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }
    if(j + 1 < c && i - 1 >= 0){
        if(Rup(i-1,j+1,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool Rdown(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }
    if(j + 1 < c && i + 1 < r){
        if(Rdown(i+1,j+1,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool Lup(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }
    if(j - 1 >= 0 && i - 1 >= 0){
        if(Lup(i-1,j-1,counter+1,m)){

            return true;
        }
    }
    return false;
}

bool Ldown(int i, int j, int counter, vector<vector<char>> m){

    if(m[i][j] == word[counter]){
        if(counter == word.size()-1){
            return true;
        }
    }else{
        return false;
    }
    if(j - 1 >= 0 && i + 1 < r){
        if(Ldown(i+1,j-1,counter+1,m)){

            return true;
        }
    }
    return false;
}
int main(){
    cin >> word;
    cin >> r >> c;
    vector<vector<char>> m (r,vector<char>(c));
    vis = vector<vector<int>> (r,vector<int>(c,0));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char temp;
            cin >> temp;
            m[i][j] = temp;
        }
    }
    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(R(i,j,0,m)){
                ans++;
            }
            if(L(i,j,0,m)){
                ans++;
            }
            if(Up(i,j,0,m)){
                ans++;
            }
            if(Down(i,j,0,m)){
                ans++;
            }
            if(Rup(i,j,0,m)){
                ans++;
            }
            if(Rdown(i,j,0,m)){
                ans++;
            }
            if(Lup(i,j,0,m)){
                ans++;
            }
            if(Ldown(i,j,0,m)){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
