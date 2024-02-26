 #include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stdio.h>

using namespace std;

int switch_time = 0;

int P(int a[], int left, int right){

    int point = a[left];

    while(left < right){
        while(left < right && a[right] >= point){
            right--;
        }
        if(left == right){
            return left;
        }
        a[left] = a[right];



//        for(int i = 0; i < 5; i++){
//            cout << a[i];
//        }
//        cout << endl;

        while(left < right && a[left] <= point){
            left++;
        }
        a[right] = a[left];

    }
//    if(left == right){
//        switch_time++;
//    }
    switch_time++;
    a[left] = point;
    return left;

}

void qsort(int a[], int left, int right){

    if(left < right){

        int t = P(a, left, right);
        qsort(a, left, t-1);
        qsort(a, t+1, right);

    }
}

void quick_sort(int a[], int length){

    qsort(a, 0, length-1);

}

int main(){

	string book;
	cin >> book;

	vector<int> b;

	for(int i = 0; i < book.length(); i++){
        switch(book[i]){
            case 'L':
                b.push_back(0);
                break;
            case 'M':
                b.push_back(1);
                break;
            case 'S':
                b.push_back(2);
                break;
        }
	}

	int a[book.length()];

	copy(b.begin(), b.end(), a);

	quick_sort(a, book.length());

	cout << switch_time << endl;

	return 0;
}
