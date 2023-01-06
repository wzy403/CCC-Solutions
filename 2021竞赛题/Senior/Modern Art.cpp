#include <iostream>
#include <stdio.h>
using namespace std;

//这是一个 m  * n 的一个画板
//画板初始值为全黑
//有一只魔法笔，笔画过的地方，黑色变金色，金色变黑色
//最后求的是这个画板上有多少金色

//下面是函数插入格式： 
 
//m = 列 
//n = 行 
//k = 画了几笔
//R 数值
//C 数值


int main(){
	
	//定义并输入所有函数 
	int m;	 
	cin>>m;
	
	int n;
	cin>>n;
	
	int k;
	cin>>k;
	
	char command;	//定义一个只储存一个string的函数 ，这里的command代表是从 行 画，还是从 列 画（R || C） 

	int pos;	//这个函数是用于定位从哪里开始画
	 
	int r[m] = {0}, c[n] = {0};	//插入一个数组（代表画板）设定全部值为0是。0代表黑色 *注：1代表金色
	 
	int countR = 0, countC = 0;	//这里是一个初始计数器，计算 R （行）画了几次；C（列）画了几次。*注：之后去重会用到 
	
	for (int i = 0; i < k; i++){	//开始判断，函数k在上边有提到，是笔画数量 
		
		cin >> command >> pos;
		
		if (command == 'R'){	//判断如果是R（换句话说就是这次指令是要在 行 上运行） 
			r[pos - 1] = !r[pos - 1];	//因为笔画过去了，所以这里的意思就是 r[这个值] = 非自己，也就是说如果 r=0 非自己就等于 1，相反同理。 
			if (r[pos - 1] == 1){	//这里检查的是如果r = 1 了就代表 r画过了一次 
				countR++;	//这边行数+1 
			} else {	//如果发现r = 0了就表示这串指令有运行了一边，因为r开始值是0，运行第一遍是1在运行一遍就是0了，
						//一个加一个减等于没加没减
						//换句话说就是去重了 
				countR--;	//这里去重，所以-1 
			}
		} else {	//else这里就表示 command = C，之后和43~50行同理 
			c[pos - 1] = !c[pos - 1];
			if (c[pos - 1] == 1){
				countC++;
			} else {
				countC--;
			}
		}
	}
	
	//计算总数 
	int sum = 0;	//定义代表 总和 的函数 
	sum = countR * n + countC * m - 2 * countR * countC;
		//{这里代表总共有多少金色}-{减去重复的||俗称去重}
	printf("%d", sum);	//输出总值 
	return 0;
}
