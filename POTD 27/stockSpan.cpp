class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                // if the stack isn't empty and the element at topmost index of the stack
                // is smaller than the current element
                // then pop the index, we need to put only that index at which 
                // the element is the previous greatest element to the current element
                st.pop();
            }
            if(st.empty()){
                res[i] = i+1;
            }
            else{
                res[i] = i - st.top();
            }
            st.push(i);
        }
        
        return res;
        
    }
    
};

// Time Complexity: O(n)
// Each element is pushed and popped from the stack at most once

// Space Complexity: O(n)
// Result array + stack in the worst case
