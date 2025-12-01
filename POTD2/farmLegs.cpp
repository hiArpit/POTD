#include <bits/stdc++.h>
using namespace std;

int possible_config(int a){
    // chicken has only 2 legs, cow has 4 legs
    int config_count = a/4 + 1;
    // a is the no. of legs
    // config_count will count all the possible configuration that can be possible with available no. of legs among cows and chickens
    // for e.g. a = 2 [2 legs counted]
    // a/4 + 1 ==> 2/4 + 1 ==> 0 + 1 ==> 1 (only 2 chickens)
    // for e.g. a = 6[ 6 legs counted]
    // 6/4 + 1 ==> 1 + 1 ==> 2 configurations possible [(1 cow, 1 chicken), and (3 chickens)] 
    return config_count;
}

int main(){
    int n;
    cin >> n;
    // no. of test cases
    
    while(n--){
        int a;
        cin >> a;
        // taking the input for no. of legs shizuku counts
        if(a%2 != 0) cout << 0;
        // filtering out the odd inputs, as no combination is possible
        else{
            int res = possible_config(a);
            cout << res;
        }
    }

    return 0;
}

// Time complexity:- O(1) for each testcase as only addition and division operations being done
// Space complexity:- O(1) no extra space being used