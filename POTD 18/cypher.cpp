#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        // Taking inputs
        int a;
        cin >> a;
        vector<int> inputs;
        for(int i=0; i<a; i++){
            int b;
            cin >> b;
            inputs.push_back(b);
        }
        
        for(int j=0; j<a; j++){
            // Process moves for each wheel
            int c;
            cin >> c;
            string s;
            cin >> s;
            int shift = 0;

            // How many shifts on one wheel
            for(char ch: s){
                if(ch == 'U') shift--;
                else if(ch == 'D') shift++;
            }
            
            inputs[j] = (inputs[j] + shift + 10)%10;
        }
        
        for(auto num: inputs){
            cout << num << " ";
        }
        cout << endl;

    }
    
    return 0;
}

// TC: O(a x c) per test case, where a is the number of wheels and c ≤ 10 (number of moves per wheel)
// SC: O(a), for storing the digits of the wheels
