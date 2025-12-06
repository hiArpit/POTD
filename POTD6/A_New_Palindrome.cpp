#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        string s;
        cin >> s;
        int str_len = s.size();
        // Taking the number of characters in the string
        if(str_len<=2){
            cout << "NO" << endl;
            n--;
            // if they are lesser than 2, it means no new palindrome can be created.
            continue;
        }
        unordered_map<char, int> freq;
        // creating hashmap to count number of unique characters
        for(int i=0; i<str_len/2; i++){
            freq[s[i]]++;
        }
        // will count the number of unique characters in the first half of the string

        if(freq.size() >=2 ){
            cout << "YES" << endl;
            // if number of unique characters is greater than 1 means new palindrome can be created, otherwise not.
        }
        else {
            cout << "NO" << endl;
        }
        n--;
    }
    return 0;
}

// TC:- O(n) for n test cases, and O(L/2) for each and every string processing, L means no of characters in a string,
// so, it will be O(n*L)
// and in the program, we are counting the number of unique characters till the first half of the string.
// SC:- O(L/2)-> O(L) for maintaining unordered map data structure, L/2 atmost, if we have unique characters.