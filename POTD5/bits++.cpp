#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 0;
    while(n){
        string s;
        cin >> s;
        if(s == "X++"){
            x++;
        }
        else if(s == "X--"){
            x--;
        }
        else if(s == "++X"){
            ++x;
        }
        else if(s == "--X"){
            --x;
        }
        n--;
    }
    cout << x;
}

// TC:- O(n) why?? depends upon the number of statements for which program will run
// SC:- O(n) why?? we are using constant extra memory space that is unaffected by the input size