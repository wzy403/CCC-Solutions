#include <bits/stdc++.h>

using namespace std;

unordered_map<int,vector<pair<int,int>>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int m,n;
	cin >> m >> n;
	int grid[m+1][n+1];

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int num;
            cin >> num;
            s[num].push_back({i,j});
            grid[i][j] = num;
        }
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> check;
    check.resize(m+1);
    for(auto &i : check){
        i.resize(n+1,0);
    }
    q.push({m,n});
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        check[temp.first][temp.second] = true;

        int mul = temp.first*temp.second;

        if(s.count(mul)){
            for(auto &i : s[mul]){
                if(!check[i.first][i.second]){
                    if(i.first == 1 && i.second == 1){
                        cout << "yes";
                        return 0;
                    }
                    q.push(i);
                }
            }
        }
    }
    cout << "no";
	return 0;
}
