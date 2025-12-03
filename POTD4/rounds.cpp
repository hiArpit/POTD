#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    // n :- number of participants
    // k :- threshold score to cross
    cin >> n >> k;
    vector<int> inputs;
    while(n){
        int a;
        cin >> a;
        inputs.emplace_back(a);
        n--;
    }
    // taking inputs

    int count = 0;
    int threshold_score = inputs[k-1];
    for(int i=0; i<inputs.size(); i++){
        if(inputs[i] >= threshold_score && inputs[i] != 0){
            // checking the eligibility of the participants to be qualified
            count++;
        }
    }

    cout << count;

    return 0;
}

// TC: O(n) - reading n inputs and then counting eligible participants
// SC: O(n) - storing the n inputs in the vector (no additional extra space used)