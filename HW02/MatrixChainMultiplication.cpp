#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int BottomUp(vector<int> p, int n){
    //cout << n << endl;
    //cout << p[n-1] << endl;
    vector<vector<int>> m(n, vector<int>(n,0));
    vector<vector<int>> s(n-1, vector<int>(n-1,0));
    int q;
    int j;

    for (int l=2 ; l < n+1 ; ++l){
        for (int i=1 ; i < n-l+2; ++i){
            j = i + l - 1;
            m[i-1][j-1] = numeric_limits<int>::max(); 
            for (int k=i ; k < j; ++k){
                q = (m[i-1][k-1])+(m[k][j-1])+(p[i-1]*p[k]*p[j]);
                if (q<m[i-1][j-1]){
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
                
            }
        }
    }

    cout << "--------------------------" << endl;
    cout << "m matrix: " << endl;
    for (int i=1 ; i < n+1 ; ++i){
        for (int j=1 ; j < n+1; ++j){
            cout << m[i-1][j-1] << endl;
        }
    }

    cout << "--------------------------" << endl;
    cout << "s matrix: " << endl;
    for (int i=1 ; i < n ; ++i){
        for (int j=1 ; j < n; ++j){
            cout << s[i-1][j-1] << endl;
        }
    }

    return m[0][n-1];
}

int main(){
    int number;
    cout << "Enter numbers of your matrix" << endl;
    cin >> number;
    vector<int> dims;
    int dim;
    
    for (int i=1; i<number+2; ++i){
        cout << "Enter the dim " << i << " :" << endl;
        cin >> dim;
        dims.push_back(dim);
    }

    int answer;
    answer = BottomUp(dims,number);
    cout << "--------------------------" << endl;
    cout << "Your minimum calculation will be: " << answer << endl;

}