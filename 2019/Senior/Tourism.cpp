#include <iostream>
#include <algorithm>

using namespace std;

int skipCount = 0;

long long MaxSum(int numList[], int skip, int k, int n){
    long long sum = 0;
    skipCount += skip;
    int i = 0;
    while(i < n){
        int maxNum = 0;
        if(i == skipCount - skip){
            for(int j = i,g = 0; g < skipCount; j++,g++){
                maxNum = max(maxNum,numList[j]);
            }
            sum += maxNum;
            i += skip;
        }else{
            for(int j = i,g = 0; g < k; j++,g++){
                maxNum = max(maxNum,numList[j]);
            }
            sum += maxNum;
            i += k;
        }
    }
    return sum;
}

int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    long long answer = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n % k == 0){
        for(int i = 0; i < n; i += k){
            int maxNum = 0;
            for(int j = i,g = 0; g < k; j++,g++){
                maxNum = max(maxNum,a[j]);
            }
            answer += maxNum;
        }
    }else{
        int num = n % k;
        int repeat = (n / k) + 1;
        long long maxAnswer = 0;
        for(int i = 0; i < repeat; i++){
            maxAnswer = max(maxAnswer,MaxSum(a,num,k,n));
        }
        answer = maxAnswer;
    }

    cout << answer;
    return 0;
}
