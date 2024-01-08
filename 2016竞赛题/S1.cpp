#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string target,key;
    cin >> target >> key;
    int wordCount[26] = {0};
    for(auto &i : target){
        if(i != '*'){
            wordCount[(int)i - (int)'a']++;
        }
    }
    int startCount = 0;
    for(auto &i : key){
        if(i != '*'){
            wordCount[(int)i - (int)'a']--;
        }else{
            startCount++;
        }
    }
    int check = 0;
    for(int i = 0; i < 26; i++){
        if(wordCount[i] < 0){
            cout << "N";
            return 0;
        }else{
            check += wordCount[i];
        }
    }
    if(check - startCount == 0){
        cout << "A";
    }
    return 0;
}
