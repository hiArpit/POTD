class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxAns;
        deque<int> d;
        // Using deque as we need to pop from the front and back 
        int cnt = 0;
        for(int i=0; i<n; i++){
            while(!d.empty() && d.front() <= i - k){
                // if the starting index of the window is greater than 
                // the index at the front of the stack, then pop it off.
                d.pop_front();
            }
            while(!d.empty() && nums[d.back()] <= nums[i]){
                d.pop_back();
                // here, we are building stack with the descending order
                // if the current element is greater than the element at the index at the end, then pop it off
            }
            d.push_back(i);
            if(i>=k-1){
                maxAns.push_back(nums[d.front()]);
                // push the element at the index at the front of the deque.
            }
        }

        return maxAns;
        
    }
};

// TC:- O(n) we are traversing for each element, the inner while loop will be considered constant, as we are pushing and popping each element at most once
// Space Complexity:
// O(n - k + 1) for the output vector (maxAns)
// O(k) for the deque (stores at most k indices)
// Overall Space Complexity: O(n)