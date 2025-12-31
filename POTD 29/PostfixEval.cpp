class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for(string s: arr){
            if(s != "+" && s != "-" && s != "*" && s != "/" &&
            s != "^"){
                // if current string is an operand, push it into the
                // stack
                st.push(stoi(s));
            }
            else{
                    // if it is an operation, then pop two elements out
                    // of the stack, then apply the current operation on them
                    int second = st.top();
                    st.pop();
                    int first = st.top();
                    st.pop();
                    if(s == "*"){
                        st.push(first*second);
                    }
                    else if(s == "/"){
                        int q = first/second;
                        int r = first%second;
                        // floor division
                        // handling negative numbers
                        if(r!=0 && ((first<0)^(second<0))){
                            // if the remainder exist, and one of the operand
                            // is negative
                            q--;
                        }
                        st.push(q);
                    }
                    else if(s == "+"){
                        st.push(first+second);
                    }
                    else if(s == "-"){
                        st.push(first-second);
                    }
                    else if(s == "^"){
                        int res = 1;
                        for(int i=0; i<second; i++){
                            res *= first;
                        }
                        st.push(res);
                    }
                }
            }
            
        return st.top();
    }
};

// TC:- O(n) why?? we are traversing each string
// SC:- O(n) why?? Stack can store up to n operands in the worst case.