class Solution {
public:
    bool isValid(string s) {
        stack<char> parantheses;
        
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                parantheses.push(ch);
                // If it is a open parantheses then push into the stack
            }
            else{
                if(parantheses.empty()) return false;
                char topB = parantheses.top();
                // if it is a closed parantheses, then retrieve the top and pop it off
                parantheses.pop();

                if((ch == ')' && topB != '(') || (ch == ']' && topB != '[') || (ch == '}' && topB != '{')){
                    return false;
                }
            }
        }

        // make sure the stack is empty after the traversal, there should be no unclosed opening brackets left
        return parantheses.empty();
    }
};

// TC:- O(n) why?? we are traversing through the string of size n, all the operations of stack are O(1)
// SC:- O(n) why?? we are using stack of size n to produce the result