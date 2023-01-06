#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int answer[t];
    for(int h = 0; h < t; h++){
        int n, l;
        cin >> n >> l;
        char m[n][l];
        bool visited[n][l];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < l; j++){
                cin >> m[i][j];
            }
        }
        queue<pair<int,int>>que;
        que.push({0,0});
        int step = 0;
        bool good = false;
        while(!que.empty()){
            pair<int,int> node = que.front();
            step++;
            int x = node.second, y = node.first;
            if(y == n - 1 && x == l - 1){
                good = true;
                break;
            }
            int comend = m[y][x];
            if(comend == '-'){
                if(x + 1 < n && visited[y][x + 1] == false){
                    que.push({y,x+1});
                }
                if(x - 1 >= 0 && visited[y][x - 1] == false){
                    que.push({y,x-1});
                }
            }else if(comend == '|'){
                if(y + 1 < y && visited[y + 1][x] == false){
                    que.push({y+1,x});
                }
                if(y - 1 >= 0 && visited[y - 1][x] == false){
                    que.push({y-1,x});
                }
            }else if(comend == '+'){
                if(y + 1 < y && visited[y + 1][x] == false){
                    que.push({y + 1,x});
                }
                if(y - 1 >= 0 && visited[y - 1][x] == false){
                    que.push({y - 1,x});
                }
                if(x + 1 < n && visited[y][x + 1] == false){
                    que.push({y,x+1});
                }
                if(x - 1 >= 0 && visited[y][x - 1] == false){
                    que.push({y,x-1});
                }
            }
            visited[y][x] = true;
            que.pop();
        }
        if(good)
            answer[h] = step;
        else
            answer[h] = -1;
    }
    for(int i = 0; i < t; i++){
        cout << answer[i] << endl;
    }
    return 0;
}
