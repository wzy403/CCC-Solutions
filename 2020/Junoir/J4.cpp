#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	string word, key;
	cin >> word >> key;

	string check = key;

    for(int i = 0; i < key.size(); i++){
        check = key.substr(i) + key.substr(0,i);
        if(word.find(check) != std::string::npos){
            cout << "yes";
            return 0;
        }
    }

	cout << "no";
	return 0;
}
