#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
set<string> globalset;

void PrintLCS(vector<vector<char>> b, string s1, int x1, int x2,string current){
    if (x1==0 or x2==0){
        //cout << current << endl;
        globalset.insert(current);
        return;
    }
    if (b[x1-1][x2-1] == 'D'){
        current += s1[x1-1];
        PrintLCS(b,s1,x1-1,x2-1,current);
    } else if (b[x1-1][x2-1] == 'L'){
        PrintLCS(b,s1,x1,x2-1,current);
    } else if (b[x1-1][x2-1] == 'U'){
        PrintLCS(b,s1,x1-1,x2,current);
    } else{
        PrintLCS(b,s1,x1,x2-1,current);
        PrintLCS(b,s1,x1-1,x2,current);
    }

    return;
}

int LCS(string s1, string s2, int x1, int x2){
    vector<vector<int>> c(x1+1, vector<int>(x2+1,0));
    vector<vector<char>> b(x1, vector<char>(x2,'U'));

    for (int j=1 ; j < x2+1 ; ++j){
        for (int i=1 ; i < x1+1; ++i){
            if (s1[i-1]==s2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i-1][j-1] = 'D';
            } else{
                c[i][j] = max(c[i-1][j],c[i][j-1]);
                if (c[i][j-1]>c[i-1][j]){
                    b[i-1][j-1] = 'L';
                } 
                if ((c[i][j-1]==c[i-1][j])){
                    b[i-1][j-1] = 'B';
                }
            }
        }
    }

    cout << "Your C matrix is: " << endl;
    for (int j=1 ; j < x2+2 ; ++j){
        for (int i=1 ; i < x1+2; ++i){
            cout << c[i-1][j-1];
        }
        cout << endl;
    }
    cout << "================================" << endl;

    cout << "Your B matrix is: " << endl;
    for (int j=1 ; j < x2+1 ; ++j){
        for (int i=1 ; i < x1+1; ++i){
            cout << b[i-1][j-1];
        }
        cout << endl;
    }
    cout << "================================" << endl;

    PrintLCS(b,s1,x1,x2,"");
    return c[x1][x2];
}

int main(){
    string seq1;
    cout << "Enter your first sequence: " << endl;
    cin >> seq1;
    string seq2;
    cout << "Enter your second sequence: " << endl;
    cin >> seq2;
    cout << "================================" << endl;
    
    int x1;
    int x2;
    x1 = seq1.size();
    x2 = seq2.size();

    int answer;
    answer = LCS(seq1,seq2,x1,x2);
    cout << "Your LCSs length is: " << answer << endl;
    cout << "These are your LCSs: " << endl;
    string str;
    for (auto itr = globalset.begin() ; itr != globalset.end() ; itr++){
        str = *itr;
        for (int i=str.length() ; i >= 0 ; i--){
            cout << str[i];
        }
        cout << endl;
    }
}