class Solution {
public:
    typedef pair<int, int> p;
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<p, vector<p>, greater<p>> smallest;
        // creating a heap that tracks the smallest score along with its index at the top
        unordered_map<int, int> hash;
        // creating hashmap to mark the marked scores
        // if marked then 1, if still unmarked 0
        int n = nums.size();
        for(int i=0; i<n; i++){
            hash[i] = 0;
            // Initially all scores are set to 0
        }
    
        for(int i=0; i<n; i++){
            smallest.push({nums[i], i});
            // push the scores to the heap
        }

        while(!smallest.empty()){
            p small_score = smallest.top();
            int point = small_score.second;
            // if the topmost score is marked, then skip
            if(hash[point] == 1){
                smallest.pop();
                continue;
            }
            // if unmarked
            score += small_score.first;
            // then add to the score
            hash[point] = 1;
            // mark the index, and then mark its adjacent indices
            if(point==0){
                hash[point+1] = 1;
            }
            else if(point == n-1){
                hash[point-1] = 1;
            }
            else{
                hash[point+1] = 1;
                hash[point-1] = 1;
            }
            smallest.pop();
        }

        return score;
    }
};

// TC:
// Building the hashmap takes O(n).
// Inserting n elements into the min-heap takes O(n log n).
// Each element is popped from the heap once, and each pop costs O(log n).
// Therefore, total time complexity is O(n log n).
// SC:
// The min-heap stores up to n elements → O(n).
// The hashmap stores n indices → O(n).
// Overall space complexity is O(n).