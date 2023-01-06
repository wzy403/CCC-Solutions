#include <iostream>
#include <string>

//typedef long long ll;

using namespace std;



int main(){

    string book;
	cin >> book;

	//return 0;

    int L = 0;
    int M = 0;
    int S = 0;

	for(int i = 0; i < book.length(); i++){
        switch(book[i]){
            case 'L':
                L++;
                break;
            case 'M':
                M++;
                break;
            case 'S':
                S++;
                break;
        }
	}

	//cout << L << ' ' << M << ' ' << S << endl;

	int L1 = 0;
	int S1 = 0;
	int M1 = 0;

	for(int i = 0; i < L; i++){
        switch(book[i]){
            case 'L':
                L1++;
                break;
            case 'S':
                S1++;
                break;
            default:
                M1++;
                break;
        }
	}


	//cout << L1 << endl;

	int how_many_move = L - L1;


	int L2 = 0;
	int M2 = 0;
    int S2 = 0;

	for(int i = L; i < L + M; i++){
        switch(book[i]){
            case 'L':
                L2++;
                break;
            case 'S':
                S2++;
                break;
            default:
                break;
        }
	}


	//cout << L2 << ' ' << S2 << endl;

    how_many_move += L2 + S2 - min(L2, M1);

	cout << how_many_move << endl;

	return 0;
}
