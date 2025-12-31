class Solution {
  public:
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string ans = "";
        int n = s.length();
        unordered_map<char, int> op_prcd;
        // Defining precendence
        op_prcd['^'] = 1;
        op_prcd['*'] = 2;
        op_prcd['/'] = 2;
        op_prcd['+'] = 3;
        op_prcd['-'] = 3;
        
        for(int i=0; i<n; i++){
            // If the current character is an operand then push it into
            // the stack
            if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                ans.push_back(s[i]);
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                // if we encounter closing parantheses, then
                // pop all the operations until we get opening parantheses
                while(!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                // applying operations based on operations precendence
                while(!st.empty() && st.top() != '(' && 
                (op_prcd[s[i]] > op_prcd[st.top()] ||
                (op_prcd[s[i]] == op_prcd[st.top()] && s[i] != '^'))){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            // pop the stack to get all the operations out of the stack
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};

// TC:- O(n) why?? traversing each character, in the inner while loop
// each operation get pushed and popped atmost once, therefore its TC is O(1)
// SC:- O(n) in the worst case