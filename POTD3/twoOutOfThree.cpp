class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, array<int, 3>> freq;
        // initializing an unordered map that has number as key and an array as value
        // the array maintains the presence of the number in each vector
        // each index of the array is corresponding to the vector whether that number is in the vector or not, if it is then put 1 
        vector<int> result;
        // to store the number that are present in more than the two vectors.
        for(auto num: nums1){
            freq[num][0] = 1;
        }
        for(auto num: nums2){
            freq[num][1] = 1;
        }
        for(auto num: nums3){
            freq[num][2] = 1;
        }

        // checking for each and every pair of the map
        for(auto it: freq){
            if(it.second[0] + it.second[1] + it.second[2] >= 2){
                result.emplace_back(it.first);
            }
        }

        return result;
    }
};

// TC:- O(n) why?? going through each vector so O(nums1.size()) + O(nums2.size()) + O(nums3.size()) = O(n)
// SC:- O(n) why?? for maintaing unordered map data structure to track the presence of each and every number of each and every vector, so O(n), n is number of unique numbers and O(m) for maintaing the numbers say m that are present in more than two vectors. so O(n) + O(m) = O(n) [n<=m]