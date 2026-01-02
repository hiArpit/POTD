class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        // Stack stores indices that represent the LEFT boundary
        // of a rectangle segment with a certain height.
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int currBar = heights[i];
            int newIndex = i;
            // newIndex will track how far LEFT the current bar
            // can extend after popping taller bars.
            while(!st.empty() && currBar < heights[st.top()]){
                 // If the current bar is smaller than the height
                // represented by the stack top, then that taller bar
                // cannot extend further to the right
                
                int height = heights[st.top()];
                int right = i;
                // first index where height is smaller
                int left = st.top();
                // left boundary of this segment
                int area = height*(right-left);
                maxArea = max(area, maxArea);
                // Current smaller bar can reuse the left boundary
                // of the popped segment
                newIndex = st.top();
                
                st.pop();
                // now pop off the index
            }

            // Push the leftmost index where currBar is valid
            st.push(newIndex);
            // Update height at newIndex to represent the compressed segment
            heights[newIndex] = currBar;
        }
        while(!st.empty()){
            // Process remaining segments in the stack.
        // These bars can extend until the end of the histogram.
            int height = heights[st.top()];
            int left = st.top();
            int right = n;
            
            int area = height*(right-left);
            maxArea = max(area, maxArea); 
            st.pop();
        }

        return maxArea;
    }
};

// TC:- O(n) why?? for evaluating each bar height and the inner while loop's TC is constant as we are pushing and popping each element atmost once
// SC:- O(n) in worst case, if we have the bar heights in ascending order