class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> sum_idx;
        // created an unordered map to map sum[key] with their corresponding occurrence[value]
        long long sum = 0;
        sum_idx[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            // Add num to sum
            int target = sum - k;
            // subtract sum from k to get the difference
            if(sum_idx.find(target) != sum_idx.end()){
                // if we get the difference in the map, it means the numbers added after the difference, equal to "k"
                count += sum_idx[target];
                // add the occurence of each target sum to the count
            }
            sum_idx[sum]++;
            // Then, increment the sum occurrence inside of map
        }

        return count;
    }
};

// TC:- O(n) why?? for traversing through the vector of size n
// SC:- O(n) why?? for maintaining unordered map of size n atmost, if we are having unique sum each time.