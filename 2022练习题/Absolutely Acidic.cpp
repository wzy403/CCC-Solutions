#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int>counter;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        counter[num]++;
    }

    priority_queue<pair<int,int>>s;
    for(auto &i : counter){
        s.push({i.second,i.first});
    }

    pair<int,int> largest = s.top();
    s.pop();
    pair<int,int> Slargest = s.top();
    s.pop();
    int answer;
    if(largest.first > Slargest.first){
        int t =  Slargest.first;
        int maxNum = Slargest.second;
        int minNum = Slargest.second;
        while(!s.empty()){
            pair<int,int> temp = s.top();
            s.pop();
            if(temp.first == t){
                maxNum = max(maxNum, temp.second);
                minNum = min(minNum, temp.second);
            }else{
                break;
            }
        }
        answer = max(abs(largest.second-maxNum),abs(largest.second-minNum));
    }else if(largest.first == Slargest.first){
        int t =  Slargest.first;
        int maxNum = max(largest.second,Slargest.second);
        int minNum = min(largest.second,Slargest.second);
        while(!s.empty()){
            pair<int,int> temp = s.top();
            s.pop();
            if(temp.first == t){
                maxNum = max(maxNum, temp.second);
                minNum = min(minNum, temp.second);
            }else{
                break;
            }
        }
        answer = abs(maxNum-minNum);
    }
    cout << answer;
    return 0;
}
