#include <iostream>
#include <vector>
using namespace std;

int TopDown(vector<int> p, int n, vector<int> v){
    //cout << n << endl;
    //cout << v[n-1] << endl;
    //cout << p[n-1] << endl;   
    int q;
    if (v[n-1] > 0){
        return v[n-1];
    }

    if (n==0){
        q = 0;
    } else{
        q = -1000;
        for (int i=1 ; i < n+1; ++i){
            q = max(q, p[i-1] + TopDown(p,n-i,v));
        }
    }

    v[n-1] = q;
    return q;
}

int main(){
    int RodLength;
    cout << "Enter your rod's length" << endl;
    cin >> RodLength;
    vector<int> Prices;
    vector<int> Values;
    int price;

    for (int i=1; i<RodLength+1; ++i){
        cout << "Enter the price of length " << i << " :" << endl;
        cin >> price;
        Prices.push_back(price);
    }
    
    for (int i=1; i<RodLength+1; ++i){
        Values.push_back(-1000);
    }

    cout << "---------------------------------" << endl;
    cout << "Your maximum value will be: " << TopDown(Prices,RodLength,Values) << endl;
  
}
