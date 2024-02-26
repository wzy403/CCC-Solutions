#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector <int> p, w, d;	//设置函数数组，数组空间待定

long long int cal_time(int x){	//计算所有朋友所需的时间；int x 代表我所在位置
	long long int time = 0;	//设定一个总时间函数
	for(int i = 0; i < n; i++){	 //计算所有朋友走到目标点所需的时间
		int go_left = p[i]-d[i];	//计算每个朋友向左和向的听力范围
		int go_right = p[i]+d[i];

		//检查目标点（我所在位置）是否已经在朋友的听力范围内，若返回值为 "是" 则跳过后续代码，并开始检查下一位朋友
		if(x >= go_left && x <= go_right) {	// go_left <= x <= go_right
			continue;	//跳过后续代码
		}

		int close;	//定义一个函数，代表向我走来最近的距离
		if (abs(x-go_left) < abs(x-go_right)){	//检测这个朋友离我的左侧更近还是右侧更近
			close = go_left;	//若离我左侧更近，那么将左边数值存为最近值。若否则相反
		}else{
			close = go_right;
		}
		time += (long long)w[i] * abs(x-close);	//计算当前朋友走向我的最短时间是多少，并添加至 time 函数中。
		//     （(long long) 为什么要在这里我自己没看懂） 意思试将后续计算转换为 long long int  类型
	}
	return time; //当全部计算完成后 返回 time 函数值（time 函数代表所有朋友走向我的总时间）

}

int main(){

	cin >> n;	//输入 n值（朋友总人数）

	//重新定义p, w, d的数组大小
	p.resize(n);
	w.resize(n);
	d.resize(n);

	//设定一个虚拟值，用于之后判断向从我出发，向左最远的朋友在哪里，和向右最远的朋友在哪里
	int left =  1000000001;
	int right = 0;

	for(int i = 0; i < n; i++) {

		cin >> p[i] >> w[i] >> d[i];	//输入p, w, d值

		left = min(left,p[i]);	//对应代码地45行，判断从我出发，距离左边我最远的朋友的距离
								//（min(值1，值2)用于判断值1和值2哪个最小，并输出最小值）
								//此处代表：若 "新最远距离 > 原最远距离" 则更新数值

		right = max(right,p[i]);	//对应代码地46行，用于判断从我出发，距离右边边我最远的朋友的距离
									//（max(值1，值2)用于判断值1和值2哪个最大，并输出最大值）
									//此处代表：若 "新最远距离 > 原最远距离" 则更新数值
	}



	long long lowest_time = 999999999999999999999999999999999999999999999;	//此处函数代表，最短用时，后续数值皆为虚拟值

	while(1){
		int dev_three_part = (right-left)/3;	//将图像分成三份，取其中两点判断， 两点分别代表我所处的位置，
												//这里是让计算机假设这两个点为最优解，并在之后的计算中不断比较答案

		//66~67行代码就是算出两点的位置，一个是左边的点，一个是右边的点
		int x1 = left + dev_three_part;
		int x2 = right - dev_three_part;

		//计算这两点分别所需的时间
		long long int pos1 = cal_time(x1);
		long long int pos2 = cal_time(x2);

		//取新定义的两点中哪个点用时最短，并更新 "lowest_time"函数值（换句话说就是，将最短用时的数值保存下来）
		lowest_time = min(lowest_time, pos1);
		lowest_time = min(lowest_time, pos2);

		//判断哪个点里 "顶点/底点"（我所在的位置）最近（亦或者说用时最短），然后保留用时最短的点（时间），"删除" 用时最长的点（时间）

		if (pos1 > pos2){	//这里判断的是：当 点1 的用时 大于 点2，那么就代表 点2 相较于 点1 是当前的最优解,
							//所以这里要删除点1的数值，并填入新值 。
			left = x1;	//删除点1原先数值（旧的数值）

		}else if (pos1 < pos2){ 	//这里判断的是：当 点1 的用时 小于 点2，那么就代表 点1 相较于 点2 是当前的最优解,
									//所以这里要删除点2的数值，并填入新值 。
			right = x2;	//删除点2原先数值（旧的数值）

		}else{	//若程序运行到此代码，则代表 点1 用时 等于 点2，换句话说就是最优解了
			break;	//这时候结束 while循环
		}
		cout << "ss" << endl;
	}

	cout << lowest_time << endl;	//输出最终答案

	return 0;
}
