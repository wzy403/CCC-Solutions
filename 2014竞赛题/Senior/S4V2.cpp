#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point{
    int x1;
    int y1;
    int x2;
    int y2;
    ll t;
};

int main(){
    int n;
    cin >> n;
    ll t;
    cin >> t;
    int yTop = INT_MAX;
    int yDown = 0;
    int xLeft = INT_MAX;
    int xRight = 0;
    queue<Point> cor;
    unordered_map<int,unordered_map<int,int>> m;
    for(ll i = 0; i < n; i++){
        int x1,y1,x2,y2;
        ll t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;

        cor.push({x1,y1,x2,y2,t});

        yTop = min(yTop,y1);
        yDown = max(yDown,y2);
        xLeft = min(xLeft,x1);
        xRight = max(xRight,x2);

    }

    int limY = yDown - yTop;
    int limX = xRight - xLeft;

    for(int i = 0; i < n; i++){
        Point p = cor.front();
        cor.pop();
        int startY = p.y1 - yTop;
        int endY = p.y2 - yTop;

        int x1 = p.x1-xLeft;
        int x2 = p.x2-xLeft;
        int t = p.t;
        for(int y = startY; y < endY; y++){
            m[y][x1] += t;
            m[y][x2] -= t;
        }
    }

    ll ans = 0;

    for(int y = 0; y <= limY; y++){
        ll sum = 0;
        if(!m.count(y)){
            continue;
        }
        for(int x = 0; x <= limX; x++){
            if(m[y].count(x)){
                sum += m[y][x];
                m[y][x];

            }
            if(sum >= t){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
