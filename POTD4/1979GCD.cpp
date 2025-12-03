class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Using built-in sort method to find smallest and largest element
        // sort(nums.begin(), nums.end());
        // Method-2:- manual method to find smallest and largest element
        int mini = INT_MAX, maxi = INT_MIN;
        // Taking the largest value of int datatype as the minium and the same for maximum
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        int a = mini;
        int b = maxi;
        // int a = nums[0];
        // int b = nums[nums.size()-1];
        int gcd = 1;
        while(a!=0 && b!=0){
            if(a>=b){
                a = a % b;
            }
            else{
                b = b % a;
            }
        }
        if(a==0){
            gcd = b;
        }
        else{
            gcd = a;
        }

        return gcd;
    }
};

// TC:- O(n) why?? Because, first we are running loop to get smallest and largest element and O(logn) steps to find GCD
// SC:- O(1) not using any extra space to get result