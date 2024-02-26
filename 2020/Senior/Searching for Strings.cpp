#include <bits/stdc++.h>

using namespace std;

int counter[26] = {0};

void countN(string n){
    for(auto &i : n){
        counter[i - 'a']++;
    }
}

bool checkH(string h){
    int *tempCounter = new int[26];
    memcpy(tempCounter,counter,sizeof(int)*26);
    for(auto &i : h){
        tempCounter[i - 'a']--;
        if(tempCounter[i - 'a'] < 0){
            delete[] tempCounter;
            return false;
        }
    }
    delete[] tempCounter;
    return true;
}

int main(){
    freopen("s3.2-09.in","r",stdin);
    freopen("outputRight.txt","w",stdout);
    string n,h;
    cin >> n >> h;
    countN(n);

    int nLength = n.length();
    int hLength = h.length();

    unordered_set<string> isD;
    for(int i = 0; i + nLength <= hLength; i++){
        string temp = h.substr(i,n.length());

        if(!isD.count(temp) && checkH(temp)){
            cout << i << endl;
            isD.insert(temp);
        }
    }

    cout << isD.size();

    return 0;
}
