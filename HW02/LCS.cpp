#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string s1, string s2, int x1, int x2){
    vector<vector<int>> c(x1+1, vector<int>(x2+1,0));
    vector<vector<char>> b(x2, vector<char>(x2,'U'));

    for (int i=1 ; i < x1+1 ; ++i){
        for (int j=1 ; j < x2+1; ++j){
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
    return c[x1][x2];
}

int main(){
    string seq1;
    cout << "Enter your first sequence: " << endl;
    cin >> seq1;
    string seq2;
    cout << "Enter your second sequence: " << endl;
    cin >> seq2;

    int x1;
    int x2;
    x1 = seq1.size();
    x2 = seq2.size();

    int answer;
    answer = LCS(seq1,seq2,x1,x2);
    cout << "Your LCS length is: " << answer << endl;
}