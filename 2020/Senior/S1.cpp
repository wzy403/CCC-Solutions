#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;

	priority_queue<pair<int,int>> record;

	for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        record.push({a,b});
	}

	double answer = 0;

	int lastTime = record.top().first;
	int lastPos = record.top().second;
	record.pop();
	while(!record.empty()){
        int time = record.top().first;
        int pos = record.top().second;
        record.pop();

        answer = max(answer, (double)abs(lastPos-pos) / abs(lastTime - time));
        lastTime = time;
        lastPos = pos;
	}

	cout << answer;
	return 0;
}
