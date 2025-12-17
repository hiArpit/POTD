class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());

        int prodLeft = 1;

        // prefix multiplication
        for(int i=0; i<nums.size(); i++){
            result[i] = prodLeft;
            prodLeft *= nums[i];
        }

        // postfix and prefix multiplication together
        int prodRight = 1;
        for(int j=nums.size()-1; j>=0; j--){
            result[j] = result[j] * prodRight;
            prodRight *= nums[j];
        }

        return result;
    }
};

// TC:- O(n) why?? we are running two linear loops, one for building prefix multiplication subarrays, another for multiplying prefix with postfix subarrays.
// SC:- O(1) why?? we are not using any extra space