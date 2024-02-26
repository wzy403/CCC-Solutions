#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string name[n];
	int bit[n];
	
	int max = 0;
	int order;
	
	for(int i =  0; i < n; i++){
		cin >> name[i];
		
		cin >> bit[i];
		
		if(bit[i] == max){
			continue;
		}else if(bit[i] > max){
			max = bit[i];
			order = i;
		}
	}
	
	
	cout << name[order] << endl;
	
	
	return 0;
}
