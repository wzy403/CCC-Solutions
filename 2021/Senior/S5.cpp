#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

//recursive implementation
int LcmOfArray(vector<int> arr, int idx){
	// lcm(a,b) = (a*b/gcd(a,b))
	if (idx == arr.size()-1){
		return arr[idx];
	}
	int a = arr[idx];
	int b = LcmOfArray(arr, idx+1);
	return (a*b/__gcd(a,b)); // __gcd(a,b) is inbuilt library function
}

int gcdOfArray(vector<int>arr, int startIdx, int endIdx){

    int gcd = arr[startIdx];
    for(int i = startIdx; i <= endIdx; i++){
        gcd = __gcd(gcd,arr[i]);
    }

    return gcd;

}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> GCDs;
    vector<pair<int,int>> index;
    vector<int> number[n+1];

    for(int i = 1; i <= n; i++){
        number[i].push_back(1);
    }

    for(int i = 0; i < m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        GCDs.push_back(z);
        index.push_back({x,y});
        for(int j = x; j <= y; j++){
            number[j].push_back(z);
        }
    }

    GCDs.resize(m);
    index.resize(m);

    vector<int> ans(n+1,0);
    for(int i = 1; i <= n; i++){
        number[i].resize(number[i].size());
        ans[i] = LcmOfArray(number[i],0);
    }

    for(int i = 0; i < m; i++){
        pair<int,int> pos = index[i];
        int gcd = GCDs[i];
        for(int j = pos.first; j <= pos.second; j++){
            if(gcdOfArray(ans,pos.first,pos.second) != gcd){
                cout << "Impossible";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
