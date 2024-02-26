#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("s2.1-01.in","r",stdin);
    int n;
    cin >> n;
    unordered_map<string,unordered_set<string>>ok;
    for(int i = 0; i < n; i++){
        unordered_set<string>temp;
        string a,b;
        cin >> a >> b;
        if(!ok.count(a) && ok.count(b)){
            unordered_set<string> b1 = ok[b];
            b1.insert(a);
            ok[b] = b1;
            temp.insert(a);
            temp.insert(b);
            ok[a] = temp;
        }else if(ok.count(a) && !ok.count(b)){
            unordered_set<string> a1 = ok[a];
            a1.insert(b);
            ok[a] = a1;
            temp.insert(a);
            temp.insert(b);
            ok[b] = temp;
        }else{
            temp.insert(a);
            temp.insert(b);
            ok[a] = temp;
            ok[b] = temp;
        }
    }

    int m;
    cin >> m;
    unordered_map<string,unordered_set<string>>nok;
    for(int i = 0; i < m; i++){
        unordered_set<string>temp;
        string a,b;
        cin >> a >> b;
        if(!nok.count(a) && nok.count(b)){
            unordered_set<string> b1 = nok[b];
            b1.insert(a);
            nok[b] = b1;
            temp.insert(a);
            temp.insert(b);
            nok[a] = temp;
        }else if(nok.count(a) && !nok.count(b)){
            unordered_set<string> a1 = nok[a];
            a1.insert(b);
            nok[a] = a1;
            temp.insert(a);
            temp.insert(b);
            nok[b] = temp;
        }else{
            temp.insert(a);
            temp.insert(b);
            nok[a] = temp;
            nok[b] = temp;
        }
    }

    int l;
    cin >> l;
    int answer = 0;
    for(int i = 0; i < l; i++){
        string a,b,c;
        cin >> a >> b >> c;
        if(ok.count(a)){
            unordered_set<string>checking = ok[a];
            int s = checking.size();
            if(checking.count(a)){
                s--;
            }
            if(checking.count(b)){
                s--;
            }
            if(checking.count(c)){
                s--;
            }
            if(s != 0){
                answer++;
                continue;
            }
        }
        if(nok.count(a)){
            unordered_set<string>checking = nok[a];
            if(checking.count(b) || checking.count(c)){
                answer++;
                continue;
            }
        }

        if(ok.count(b)){
            unordered_set<string>checking = ok[b];
            int s = checking.size();
            if(checking.count(a)){
                s--;
            }
            if(checking.count(b)){
                s--;
            }
            if(checking.count(c)){
                s--;
            }
            if(s != 0){
                answer++;
                continue;
            }
        }
        if(nok.count(b)){
            unordered_set<string>checking = nok[b];
            if(checking.count(a) || checking.count(c)){
                answer++;
                continue;
            }
        }

        if(ok.count(c)){
            unordered_set<string>checking = ok[c];
            int s = checking.size();
            if(checking.count(a)){
                s--;
            }
            if(checking.count(b)){
                s--;
            }
            if(checking.count(c)){
                s--;
            }
            if(s != 0){
                answer++;
                continue;
            }
        }
        if(nok.count(c)){
            unordered_set<string>checking = nok[c];
            if(checking.count(b) || checking.count(a)){
                answer++;
                continue;
            }
        }
    }
    cout << answer;
    return 0;
}
