class MinStack {
    stack<int> st;
    stack<int> minSt;
    // Maintaining two stacks
    // One for pushing and popping elements that are coming through inputs
    // Another for tracking the current minimum element

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!minSt.empty() && minSt.top() > val){
            // If the minSt is not empty and the current element
            // is smaller than the element at the top of minSt
            minSt.push(val);
        }
        else if(minSt.empty()){
            // if the minSt is empty
            minSt.push(val);
        }
        else{
            // if the current element is larger than the current minimum element
            minSt.push(minSt.top());
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // TC:- O(1) for all operations
 // SC:- O(n) for using two stack 