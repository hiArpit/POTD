#include <bits/stdc++.h>

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int good_count = 0;
        map<int, int> freq_nums;
        for(auto num: nums){
            good_count += freq_nums[num];
            freq_nums[num]++;
        }
        return good_count;
    }
};