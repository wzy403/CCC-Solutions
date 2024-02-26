#include <bits/stdc++.h>

using namespace std;

vector<int> letterCounter(string& key){
    vector<int> counter(3,0);
    for(auto &i : key){
        switch(i){
            case 'A':
                counter[0]++;
                break;
            case 'B':
                counter[1]++;
                break;
            case 'C':
                counter[2]++;
                break;
            default:
                break;
        }
    }
    return counter;
}

unordered_map<string,int> letterTable(string& word, vector<int>& wordCount){
    unordered_map<string,int> counterTable;
    //in A
    for(int i = 0; i < wordCount[0]; i++){
        if(word[i] == 'A'){
            counterTable["a_in_a"]++;
        }else if(word[i] == 'B'){
            counterTable["b_in_a"]++;
        }else{
            counterTable["c_in_a"]++;
        }
    }

    //in B
    int lenForB = wordCount[0] + wordCount[1];
    for(int i = wordCount[0]; i < lenForB; i++){
        if(word[i] == 'A'){
            counterTable["a_in_b"]++;
        }else if(word[i] == 'B'){
            counterTable["b_in_b"]++;
        }else{
            counterTable["c_in_b"]++;
        }
    }

    //in C
    int lenForC = word.size();
    for(int i = lenForB; i < lenForC; i++){
        if(word[i] == 'A'){
            counterTable["a_in_c"]++;
        }else if(word[i] == 'B'){
            counterTable["b_in_c"]++;
        }else{
            counterTable["c_in_c"]++;
        }
    }

    return counterTable;
}

void swichPos(int pos, string& word, vector<int>& wordCount, unordered_map<string,int>& wordCountTable){
    //changes A
    if(word[pos-1] == 'A'){
        wordCountTable["a_in_a"]--;
        wordCountTable["a_in_c"]++;
    }else if(word[pos-1] == 'B'){
        wordCountTable["b_in_a"]--;
        wordCountTable["b_in_c"]++;
    }else{
        wordCountTable["c_in_a"]--;
        wordCountTable["c_in_c"]++;
    }

    //changes B start
    pos = pos + wordCount[0];
    if(word[pos-1] == 'A'){
        wordCountTable["a_in_b"]--;
        wordCountTable["a_in_a"]++;
    }else if(word[pos-1] == 'B'){
        wordCountTable["b_in_b"]--;
        wordCountTable["b_in_a"]++;
    }else{
        wordCountTable["c_in_b"]--;
        wordCountTable["c_in_a"]++;
    }

    //changes c start
    pos = pos + wordCount[1];
    if(word[pos-1] == 'A'){
        wordCountTable["a_in_c"]--;
        wordCountTable["a_in_b"]++;
    }else if(word[pos-1] == 'B'){
        wordCountTable["b_in_c"]--;
        wordCountTable["b_in_b"]++;
    }else{
        wordCountTable["c_in_c"]--;
        wordCountTable["c_in_b"]++;
    }
}

int main(){
    string word;
    cin >> word;
    vector<int> wordCount = letterCounter(word);
    unordered_map<string,int> wordCountTable = letterTable(word,wordCount);

    int answer1 = (wordCount[0] - wordCountTable["a_in_a"]) + (wordCount[1] - wordCountTable["b_in_b"])
                - min(wordCountTable["b_in_a"],wordCountTable["a_in_b"]);

    string wordNew = word + word;
    for(int i = 1; i < word.size(); i++){
        swichPos(i,wordNew,wordCount,wordCountTable);
        int tempAns = (wordCount[0] - wordCountTable["a_in_a"]) + (wordCount[1] - wordCountTable["b_in_b"])
                - min(wordCountTable["b_in_a"],wordCountTable["a_in_b"]);

        answer1 = min(answer1,tempAns);
    }

    reverse(word.begin(),word.end());

    wordCountTable = letterTable(word,wordCount);

    int answer2 = (wordCount[0] - wordCountTable["a_in_a"]) + (wordCount[1] - wordCountTable["b_in_b"])
                - min(wordCountTable["b_in_a"],wordCountTable["a_in_b"]);

    string wordNew2 = word + word;
    for(int i = 1; i < word.size(); i++){
        swichPos(i,wordNew2,wordCount,wordCountTable);
        int tempAns = (wordCount[0] - wordCountTable["a_in_a"]) + (wordCount[1] - wordCountTable["b_in_b"])
                - min(wordCountTable["b_in_a"],wordCountTable["a_in_b"]);
        answer2 = min(answer2,tempAns);
    }
    cout << min(answer1,answer2);
    return 0;
}
