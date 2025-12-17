class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end()-k);
        // reverse the portion from the starting till before k elements
        reverse(nums.end()-k, nums.end());
        // reverse the porition from the last k elements till the end
        reverse(nums.begin(), nums.end());
        // reverse the entire array
    }
};

// TC:- O(n) why?? we are using reverse that takes O(n) time
// SC:- O(1) why?? we are not using any extra space