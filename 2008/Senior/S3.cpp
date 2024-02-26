#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(){
    int row,col;
    cin >> row >> col;
    vector<vector<char>> m(row,vector<char>(col));
    vector<vector<int>> cost(row,vector<int>(col,INT_MAX));
    vector<vector<bool>> vis(row,vector<bool>(col,false));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            char temp;
            cin >> temp;
            m[i][j] = temp;
        }
    }

    if(m[0][0] == '*' || m[row-1][col-1] == '*'){
        return -1;
    }

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    q.push({0,{0,0}});
    cost[0][0] = 1;

    while(!q.empty()){
        pair<int,int> pos = q.top().second;
        q.pop();

        int r = pos.first;
        int c = pos.second;

        int tempCost = cost[r][c] + 1;

        if(!vis[r][c]){
            vis[r][c] = true;

            if(m[r][c] == '-'){

                if(c-1 >= 0 && tempCost < cost[r][c-1]){
                    cost[r][c-1] = tempCost;
                    q.push({tempCost,{r,c-1}});
                }
                if(c+1 < col && tempCost < cost[r][c+1]){
                    cost[r][c+1] = tempCost;
                    q.push({tempCost,{r,c+1}});
                }

            }else if(m[r][c] == '|'){

                if(r-1 >= 0 && tempCost < cost[r-1][c]){
                    cost[r-1][c] = tempCost;
                    q.push({tempCost,{r-1,c}});
                }
                if(r+1 < row && tempCost < cost[r+1][c]){
                    cost[r+1][c] = tempCost;
                    q.push({tempCost,{r+1,c}});
                }

            }else if(m[r][c] == '+'){

                if(c-1 >= 0 && tempCost < cost[r][c-1]){
                    cost[r][c-1] = tempCost;
                    q.push({tempCost,{r,c-1}});
                }
                if(c+1 < col && tempCost < cost[r][c+1]){
                    cost[r][c+1] = tempCost;
                    q.push({tempCost,{r,c+1}});
                }
                if(r-1 >= 0 && tempCost < cost[r-1][c]){
                    cost[r-1][c] = tempCost;
                    q.push({tempCost,{r-1,c}});
                }
                if(r+1 < row && tempCost < cost[r+1][c]){
                    cost[r+1][c] = tempCost;
                    q.push({tempCost,{r+1,c}});
                }

            }
        }
    }

    if(cost[row-1][col-1] != INT_MAX){
        return cost[row-1][col-1];
    }else{
        return -1;
    }
}

int main(){
    int t;
    cin >> t;
    vector<int> ans;
    for(int q = 0; q < t; q++){
        ans.push_back(solve());
    }
    for(auto &i : ans){
        cout << i << endl;
    }
    return 0;
}
