#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	vector<int> all_num;
	
	int count = 0;
	while (1){
		int a;
		cin >> a;
		if(a == 99999){
			break;
		}
		all_num.push_back(a);
		count++;
	}
	
	all_num.resize(count);
	string d;
	
	for(int i = 0; i < count; i++){
		int a = all_num[i]/10000%10;
		int b = all_num[i]/1000%10;
		
		int remain = all_num[i] - (a*10000 + b*1000);
				
		if(a + b == 0){
			cout << d << remain << endl;
		}else if((a + b)%2 == 0){
			d = "right ";
			cout << "right " << remain << endl;
		}else{
			d = "left ";
			cout << "left " << remain << endl;
		}
	}
	
	return 0;
} 
