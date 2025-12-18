#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // Taking the no. of test cases

    while(n){
        int a;
        cin >> a;
        
        // If the input is not divisible by 4, then that means it can't be divided into even parts
        if(a % 4 != 0){
            cout << "NO";
            n--;
            continue;
        }
        
        cout << "YES\n";
        vector<int> result;
        // Building a vector to store results

        // Calculating even side
        int sumA = 0;
        for(int i=1; i<=a/2; i++){
            int val = 2*i;
            result.push_back(val);
            sumA += val;
        }

        int sumB = 0;
        
        // Calculating odd side
        for(int i=1; i<a/2; i++){
            int val = 2*i - 1;
            result.push_back(val);
            sumB += val;
        }
        
        // Putting the left sum into the odd side's end
        int gap = sumA - sumB;
        result.push_back(gap);
        
        for(auto num: result){
            cout << num << " ";
        }
        cout << endl;
        n--;
    }
}

// Time Complexity: O(a) per test case
// Space Complexity: O(a) per test case
