class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        int barrier = -1;
        // Finding the longest prefix to match
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                barrier = i;
                break;
            }
        }
        // sorted in descending order
        if(barrier == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        int greater = -1;
        int greater_idx = -1;
        // Finding the element greater than nums[barrier] but the smaller in the greatest pool
        for(int j=nums.size()-1; j>=barrier+1; j--){
            if(nums[j] > nums[barrier]){
                greater = nums[j];
                greater_idx = j;
                break;
            }
        }
        // swap the element at the barrier and greater_idx
        int temp = nums[barrier];
        nums[barrier] = nums[greater_idx];
        nums[greater_idx] = temp;

        // Now, sort the remaining elements after the barrier
        sort(nums.begin()+barrier+1, nums.end());
    }
};

// TC: O(n log n)
// We traverse the array twice:
//   - O(n) to find the barrier
//   - O(n) to find the element just greater than nums[barrier]
// The dominant operation is sorting the suffix, which costs O(k log k),
// where k ≤ n. In the worst case, k = n, so sorting takes O(n log n).
// Therefore: O(n) + O(n) + O(n log n) = O(n log n)

// SC: O(1), because we only use constant extra space.