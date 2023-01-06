#include <bits/stdc++.h>
#include <numeric>

using namespace std;

const int Mxn = 150005, Mxm = 150005, Mxz = 21;
int st[Mxn*4];
vector<int> ans;

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

void build(int i = 1, int tl = 1, int tr = Mxn) {
    if (tl == tr) {
        st[i] = ans[tl];
    } else {
        int mid = tl + (tr - tl) / 2;
        build(i*2, tl, mid);
        build(i*2+1, mid+1, tr);
        st[i] = __gcd(st[i*2], st[i*2+1]);
    }
}

int query(int l, int r, int i = 1, int tl = 1, int tr = Mxn) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return st[i];
    }
    int mid = tl + (tr - tl) / 2;
    return __gcd(query(l, min(r, mid), i*2, tl, mid),
                query(max(l, mid+1), r, i*2+1, mid+1, tr));
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> diffArr;
    diffArr.resize(n+3);
    for(int i = 0; i < n+3; i++){
        diffArr[i].resize(17);
        for(int j = 0; j < 17; j++){
            diffArr[i][j] = 0;
        }
    }

    vector<int> GCDs(m);
    vector<pair<int,int>> index;
    for(int i = 1; i <= m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        index.push_back({x,y});
        GCDs[i-1] = z;
        diffArr[x][z]+=1;
        diffArr[y+1][z]-=1;
    }

    vector<vector<int>> newArr;
    newArr.resize(n+3);
    for(int i = 0; i < n+3; i++){
        newArr[i].resize(17);
        for(int j = 0; j < 17; j++){
            newArr[i][j] = 0;
        }
    }

    vector<int> numbersGCD[n+1];
    for(int i = 1; i <= n; i++){
        numbersGCD[i].push_back(1);
        for(int j = 1; j < 17; j++){
            newArr[i][j] = newArr[i-1][j] + diffArr[i][j];
            if(newArr[i][j] > 0){
                numbersGCD[i].push_back(j);
            }
        }
    }

    ans.resize(Mxn);
    for(int i = 1; i <= n; i++){
        numbersGCD[i].resize(numbersGCD[i].size());
        ans[i] = LcmOfArray(numbersGCD[i],0);
    }

    build();

    GCDs.resize(m);
    index.resize(m);

    for(int i = 0; i < m; i++){
        pair<int,int> pos = index[i];
        int gcd = GCDs[i];
        if (query(pos.first, pos.second) != gcd) {
          cout << "Impossible";
          return 0;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}
