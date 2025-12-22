class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        // To form the number n using deci-binary numbers (digits 0 or 1 only), each deci-binary number can contribute at most 1 to any digit position.
        // Therefore, the minimum number of deci-binary numbers required is equal to the maximum digit present in n.
        // E.g. to get 32, we need 3 1s atleast at ten's place and 2 1st atmost at unit place
        for(char ch: n){
            int dgt = ch - '0';
            maxi = max(dgt, maxi);
        }

        return maxi;
    }
};

// TC: O(n) — we traverse each digit of the string once
// SC: O(1) — only a constant variable is used