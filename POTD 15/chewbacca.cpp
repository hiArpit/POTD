#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s = to_string(n);
    int size = s.size();
    for(int i=0; i<size; i++){
        int rem = s[i] - '0';
        if(i==0 && s[i] == '9'){
            continue;
        }
        
        else{
            s[i] = char('0' + min(rem, 9-rem));
        }
    }
    cout << s;
    return 0;
}

// TC:- O(n) why?? as we are traversing through each digit once
// SC:- O(n) why?? we are using extra memory space to store string of size n