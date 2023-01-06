#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int m, n;
int room[1000][1000];
int pr[1000][1000];
int dfs(int r, int c){
	if(r == m - 1 && c == n - 1){
		return 1;
	}
	if(pr[r][c] == 1){
		return 0;
	}
	pr[r][c] = 1;
	int j;
	int result;
	for(int i = 1; i <= sqrt(room[r][c]); i++){
		if(room[r][c] % i == 0){
			j = room[r][c] / i;
			if(i <= m && j <= n){
				result = dfs(i - 1, j - 1);
				if(result == 1){
					pr[r][c] = 0;
					return 1;
				}
			}
			if(i <= n && j <= m){
				result = dfs(j - 1, i - 1);
				if(result == 1){
					pr[r][c] = 0;
					return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> room[i][j];
			pr[i][j] = 0;
		}
	}
	if(dfs(0, 0) == 1){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	return 0;
}
