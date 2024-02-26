#include <bits/stdc++.h>

using namespace std;

int isP(string &s, int left, int right){
    if(s.size() < 1 || left > right){
        return 0;
    }
    while(left >= 0 && right < s.size()&& s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}

int main(){
    string word;
    cin >> word;
    int ans = 0;
    for(int i = 0; i < word.size(); i++){
        int lenOdd = isP(word,i,i);
        int lenEven = isP(word,i,i+1);
        ans = max(ans,max(lenOdd,lenEven));
    }
    cout << ans;
    return 0;
}
