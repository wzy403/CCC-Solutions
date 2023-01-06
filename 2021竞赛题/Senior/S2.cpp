#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int *mCount = new int[m];
    int *nCount = new int[n];
    for(int i = 0; i < m; i++){
        mCount[i] = 0;
    }
    for(int i = 0; i < n; i++){
        nCount[i] = 0;
    }
    int mNum = 0, nNum = 0;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        string a;
        int num;
        cin >> a >> num;
        if(a == "R"){
            if(!mCount[num-1]){
                mNum++;
            }else{
                mNum--;
            }
            mCount[num-1] = !mCount[num-1];
        }else{
            if(!nCount[num-1]){
                nNum++;
            }else{
                nNum--;
            }
            nCount[num-1] = !nCount[num-1];
        }
    }
    int sum = mNum*(n-nNum) + nNum*(m-mNum);
    cout << sum;
    delete[] nCount;
    delete[] mCount;
    return 0;
}
