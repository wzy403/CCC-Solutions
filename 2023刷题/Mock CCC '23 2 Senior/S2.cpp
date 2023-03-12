#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> stick;
int ans = 0;

void bk(int tempAns, vector<bool> vis){
    for(int i = 0; i < stick.size(); i++){
        if(vis[i]){
            continue;
        }
        for(int j = i+1; j < stick.size(); j++){
            if(vis[j]){
                continue;
            }
            for(int g = j+1; g < stick.size(); g++){
                if(vis[i]){
                    continue;
                }
                int a = stick[i];
                int b = stick[j];
                int c = stick[g];
                if(a+b > c && a+c > b && b+c > a){
                    ans = max(tempAns+a+b+c, ans);
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    stick.resize(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        stick[i] = temp;
    }
    for(int i = 0; i < stick.size(); i++){
        for(int j = i+1; j < stick.size(); j++){
            for(int g = j+1; g < stick.size(); g++){
                int a = stick[i];
                int b = stick[j];
                int c = stick[g];
                if(a+b > c && a+c > b && b+c > a){
                    vector<bool> vis(n);
                    vis[i] = vis[j] = vis[g];
                    bk(a+b+c,vis);
                }

            }
        }
    }
    cout << ans << endl;
    return 0;
}
