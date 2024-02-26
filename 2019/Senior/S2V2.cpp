#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);


    int numMax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        numMax = max(numMax,num[i]);
    }

    vector<int> primes;
    bool isP = false;
    bool breakLine = false;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    int sum = numMax * 2;
    for (int i = 2; i < sum; i++)
    {
        if (((i + 1) % 6 == 0) || ((i - 1) % 6 == 0))
        {
            isP = true;
            int a = sqrt(i);
            for (int j = 2; j <= a; j++)
            {
                if (i % j == 0)
                {
                    isP = false;
                    break;
                }
            }
            if (isP == true)
            {
                primes.push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int tempSum = num[i] * 2;

        for(int j = 0; j < primes.size(); j++){
            if(tempSum - primes[j] <= 0){
                continue;
            }
            int target = tempSum - primes[j];

            int low = 0, high = primes.size();
            bool b = false;
            while(low <= high){
                int mid = low + (high-low)/2;

                if(primes[mid] < target){
                    low = mid + 1;
                }else if(primes[mid] > target){
                    high = mid - 1;
                }else{
                    cout << primes[j] << ' ' << primes[mid] << "\n";
                    b = true;
                    break;
                }
            }
            if(b){
                break;
            }
        }
    }
    return 0;
}
