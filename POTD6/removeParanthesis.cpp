class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int bal = 0;
        for(auto ch: s){
            if(ch=='('){
                if(bal > 0){
                    // it's not the first '(', therefore it will be added into the result string
                    res += ch;
                }
                bal++;
                // whenever '(' comes the balance will be increased
            }
            else {
                bal--;
                // whenever ')' comes the balance will be decremented
                // then we check whether balance > 0 or not to prevent adding last ')' into the result
                if(bal > 0){
                    // If it is, the character ')' will be added to the result string
                    res += ch;
                }
            }
        }

        return res;
    }
};

// TC:- O(n) as we are traversing through the string character one by one
// SC:- O(n) as we are using an extra space of O(n) to store inner parantheses