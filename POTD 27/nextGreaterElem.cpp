class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        // Initializing the res vector of size n with default size n
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                // here, we are running while loop and it will run
                // as long as we don't find the next greater element of the
                // element at the topmost index
                res[st.top()] = arr[i];
                // when we find it, we will pop the current topmost index
                st.pop();
            }
            st.push(i);
        }
        
        return res;
        
    }
};

// Time Complexity: O(n)
// Each index is pushed and popped from the stack at most once (amortized analysis)

// Space Complexity: O(n)
// Result array + stack in the worst case
