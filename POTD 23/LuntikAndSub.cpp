#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        int cnt0 = 0;
        int cnt1 = 0;
        
        for(int i=0; i<a; i++){
            int b;
            cin >> b;
            if(b == 0){
                cnt0++;
            }
            else if(b == 1){
                cnt1++;
            }
        }
        
        cout << cnt1 * (1LL << cnt0) << "\n";
    }
    
    return 0;
}