#include <bits/stdc++.h>

using namespace std;

int n,m;
void checkCam(int row,int col,vector<vector<char>>& grid, vector<vector<int>>& vis){
    //col
    for(int i = col; i >= 0; i--){
        if(grid[row][i] == 'W'){
            break;
        }else if(grid[row][i] == '.' || grid[row][i] == 'S'){
            vis[row][i] = -1;
        }
    }
    for(int i = col; i < m; i++){
        if(grid[row][i] == 'W'){
            break;
        }else if(grid[row][i] == '.' || grid[row][i] == 'S'){
            vis[row][i] = -1;
        }
    }

    //row
    for(int i = row; i >= 0; i--){
        if(grid[i][col] == 'W'){
            break;
        }else if(grid[i][col] == '.' || grid[row][i] == 'S'){
            vis[i][col] = -1;
        }
    }
    for(int i = row; i < n; i++){
        if(grid[i][col] == 'W'){
            break;
        }else if(grid[i][col] == '.' || grid[row][i] == 'S'){
            vis[i][col] = -1;
        }
    }
}

void dfs(int r, int c, int step, vector<vector<char>>& grid, vector<vector<int>>& vis){
    if(vis[r][c] > step){
        vis[r][c] = step;
        if(grid[r][c] == '.' || grid[r][c] == 'S'){
            if(r+1 < n){
                dfs(r+1,c,step+1,grid,vis);
            }
            if(r-1 >= 0){
                dfs(r-1,c,step+1,grid,vis);
            }
            if(c+1 < m){
                dfs(r,c+1,step+1,grid,vis);
            }
            if(c-1 >= 0){
                dfs(r,c-1,step+1,grid,vis);
            }
        }else if(grid[r][c] == 'L'){
            if(c-1 >= 0){
                dfs(r,c-1,step,grid,vis);
            }else{
                vis[r][c] = -1;
            }
        }else if(grid[r][c] == 'R'){
            if(c+1 < m){
                dfs(r,c+1,step,grid,vis);
            }else{
                vis[r][c] = -1;
            }
        }else if(grid[r][c] == 'D'){
            if(r+1 < n){
                dfs(r+1,c,step,grid,vis);
            }else{
                vis[r][c] = -1;
            }
        }else if(grid[r][c] == 'U'){
            if(r-1 >= 0){
                dfs(r-1,c,step,grid,vis);
            }else{
                vis[r][c] = -1;
            }
        }

    }
}

int main(){
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
    int r,c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'W' || grid[i][j] == 'C'){
                vis[i][j] = -1;
            }else if(grid[i][j] == 'S'){
                r = i;
                c = j;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'C'){
                checkCam(i,j,grid,vis);
            }
        }
    }

    dfs(r,c,0,grid,vis);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                if(vis[i][j] == INT_MAX){
                    cout << -1 << "\n";
                }else{
                    cout << vis[i][j] << "\n";
                }
            }
        }
    }
    return 0;
}
