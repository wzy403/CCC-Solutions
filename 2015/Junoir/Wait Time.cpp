#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int m;
    cin >> m;
    int timeCount[m];
    int friendCount[m];
    int friendCopy[m];

    int time = 0;
    for(int i = 0; i < m; i++){
        char a;
        int num;
        cin >> a >> num;

        if(a == 'W'){
            timeCount[i] = num;
            friendCount[i] = -1;
            friendCopy[i] = -1;
            time = time - 1 + num;
        }else{
            timeCount[i] = time;
            friendCount[i] = num;
            friendCopy[i] = num;
            time++;
        }
    }

    vector<int>removeRepeat;
    sort(friendCopy,friendCopy+m);
    int checker = friendCopy[0];
    int t = 0;
    for(int i = 0; i < m; i++){
        if(checker == friendCopy[i]){
            continue;
        }else{
            checker = friendCopy[i];
            removeRepeat.push_back(checker);
            t++;
        }
    }

    int answer[t] = {0};
    for(int i = 0; i < t; i++){
        int loopCount = 0;
        int target = removeRepeat[i];
        int pos = find(friendCount,friendCount+m,target) - friendCount;
        loopCount++;
        for(int j = pos+1; j < m; j++){
            if(friendCount[j] != target){
                continue;
            }else{
                loopCount++;
                if(loopCount % 2 == 0){
                    answer[i] += timeCount[j] - timeCount[pos];
                }else{
                    pos = j;
                }
            }
        }
        if(loopCount % 2 != 0){
            answer[i] = -1;
        }
    }


    for(int i = 0; i < removeRepeat.size(); i++){
        cout << removeRepeat[i] << ' ' << answer[i] << endl;
    }
    return 0;
}
