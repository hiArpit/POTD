#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, w, n;
    // k for the cost of first banana
    // w for the initial dollar the buyer has
    // n for no. of banana he wants
    cin >> k >> w >> n;
    int t_price = 0, borrow = 0;
    while(n){
        t_price += k*n;
        n--;
    }
    
    if(w < t_price) borrow = t_price - w;
    
    cout << borrow;
}