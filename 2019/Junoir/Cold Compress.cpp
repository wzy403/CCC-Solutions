#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    int wordCount[n][80];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 80; j++){
            wordCount[i][j] = 0;
        }
    }

    char answerWord[n][80];
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        int counter = 0;
        char tempLetter = word[0];
        answerWord[i][counter] = tempLetter;
        for(int j = 0; j < word.length(); j++){
            if(word[j] == tempLetter){
                wordCount[i][counter]++;
            }else{
                counter++;
                tempLetter = word[j];
                answerWord[i][counter] = tempLetter;
                wordCount[i][counter]++;
            }

        }
    }

    for(int i = 0; i < n; i++){
        int counter = 0;
        for(auto &j : answerWord[i]){
            if(j != '\0'){
                cout << wordCount[i][counter] << ' ' << j << ' ';
                counter++;
            }else{
                break;
            }
        }
        cout << "\n";
    }

    return 0;
}
