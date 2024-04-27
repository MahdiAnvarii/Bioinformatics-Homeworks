#include <iostream>
#include <vector>
using namespace std;

int BottomUp(vector<int> p, int n){
    //cout << n << endl;
    //cout << p[n-1] << endl;
    vector<int> v;
    v.push_back(0);
    int q;

    for (int j=1 ; j < n+1 ; ++j){
        q = -1000;
        for (int i=1 ; i < j+1; ++i){
            q = max(q, p[i-1] + v[j-i]);
        }
        v.push_back(q);
        //v[j] = q;
    }

    return v[n];
}

int main(){
    int RodLength;
    cout << "Enter your rod's length" << endl;
    cin >> RodLength;
    vector<int> Prices;
    int price;

    for (int i=1; i<RodLength+1; ++i){
        cout << "Enter the price of length " << i << " :" << endl;
        cin >> price;
        Prices.push_back(price);
    }
    
    cout << "----------------------------" << endl;
    cout << "Your maximum value will be: " << BottomUp(Prices,RodLength) << endl;
  
}