#include <bits/stdc++.h>

using namespace std;

int counterN[26] = {0};
int counterH[26] = {0};

void countN(string n){
    for(auto &i : n){
        counterN[i - 'a']++;
    }
}

void countH(string h){
    for(auto &i : h){
        counterH[i - 'a']++;
    }
}

bool check(){
    for(int i = 0; i < 26; i++){
        if(counterN[i] != counterH[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string n,h;
    cin >> n >> h;
    countN(n);
    int lim = h.length() - n.length() + 1;
    int lengthN = n.length();

    unordered_set<unsigned long long> answer;
    hash<string>to_hash;

    int skip = 0;
    for(int i = 0; i < lim; i++){
        if(i == 0){
            string temp = h.substr(0,lengthN);
            countH(temp);
            if(check()){
                answer.insert(to_hash(temp));
            }
            continue;
        }
        counterH[h[i-1] - 'a']--;
        counterH[h[i+lengthN-1] - 'a']++;
        if(counterN[h[i+lengthN-1] - 'a'] == 0){
            skip = lengthN - 1;
            continue;
        }
        skip--;
        if(skip < 0){
            skip = 0;
        }
        if(skip == 0 && check()){
            answer.insert(to_hash(h.substr(i,lengthN)));
        }
    }

    cout << answer.size();
    return 0;
}
