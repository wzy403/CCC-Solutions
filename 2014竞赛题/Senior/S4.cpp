#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int T;
    cin >> T;
    int xL = 1e9+1, xR = 0;
    int yL = 1e9+1, yR = 0;
    vector<vector<int>> cordnate;
    for(int i = 0 ; i < n; i++){
        int x1,y1;
        int x2,y2;
        int t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        cordnate.push_back({x1,y1,x2,y2,t});
        xL = min(xL,x1);
        xR = max(xR,x2);
        yL = min(yL,y1);
        yR = max(yR,y2);
    }
    int limY = yR-yL;
    int limX = xR-xL;
    //vector<vector<int>> diff(limY,vector<int>(limX,0));
    unordered_map<int,map<int,int>> diff;
    for(auto &c : cordnate){
        for(int y = c[1] - yL; y < c[3]-yL; y++){
            diff[y][c[0]-xL] += c[4];
            diff[y][c[2]-xL] -= c[4];
        }
    }

    int answer = 0;
    for(int y = 0; y < limY; y++){
        int sum = diff[y][0];
        if(sum >= T){
            answer++;
        }
        for(int x = 1; x < limX; x++){
            sum += diff[y][x];
            if(sum >= T){
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}
