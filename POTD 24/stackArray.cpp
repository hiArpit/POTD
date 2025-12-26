class myStack {
    
    vector<int> st;
    int top;
    int size = 0;
    
  public:
    myStack(int n) {
        // Define Data Structures
        st.resize(n);
        top = -1;
        size = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top == -1){
            return true;
        }
        return false;
        
    }

    bool isFull() {
        // check if the stack is full
        if(top == size-1){
            return true;
        }
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top == size-1){
            return;
        }
        top++;
        st[top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(top == -1){
            return;
        }
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(top == -1){
            return -1;
        }
        return st[top];
    }
};

// TC:- O(1) of all operations
// SC:- O(n) to maintain stack of size n