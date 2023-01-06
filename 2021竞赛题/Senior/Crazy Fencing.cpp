#include <iostream>
using namespace std;
int main(){
	
	//int 为定义数值为整数 
    int n;	//定义n值为整数 
    
    //cin 的意思是输入（input）数值 
    cin >> n;	//n值输入 
    
    if (n < 1){
    	return 0;
	}
    int h[n + 1];	//定义h值为列表值，列表值内列表数量为 n+1。（这代表列表值仅有n+1个数值） 
    int w[n];	//定义w值为列表值，列表值内列表数量为 n 个单位（数值） 
    for (int i = 0; i <= n; i++){
    	cin >> h[i];	//输入h值 
	}
	for (int i = 0; i < n; i++){
		cin >> w[i];	//输入w值 
	}
	long double sum = 0;	//定义sum为小数值；long double 是指大的小数（为了防止数值溢出） 
	for (int i = 0; i < n; i++){
		sum += (h[i] + h[i + 1]) * w[i] / 2.0;
	}
    printf("%Lf\n", sum);
    //cout << sum << endl;
	return 0;
}
