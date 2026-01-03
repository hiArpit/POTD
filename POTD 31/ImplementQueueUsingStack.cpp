class MyQueue {
    stack<int> input;
    stack<int> output;
    // Having two stacks
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
        // push the new elements into the 1st stack
    }
    
    int pop() {
        if(output.empty()){
            // if the 2nd stack is empty
            // then push all the elements of 1st stack into the 2nd stack
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int topN = output.top();
        output.pop();
        return topN;

    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int topN = output.top();
        return topN;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// TC:
// push()  -> O(1)
// empty() -> O(1)
// pop() & peek():
//   - Worst case: O(n) when output stack is empty and transfer happens
//   - Amortized: O(1), because each element is moved at most once
// SC:- O(n) as we are maintaining two stacks