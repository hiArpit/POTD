class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char, int> freq;
        // making an unordered map to count frequency of each character
        for(char ch: s){
            freq[ch]++;
        }
        
        priority_queue<int> maxH;
        // making a maxHeap to get the most frequency at the top
        
        for(auto it: freq){
            maxH.push(it.second);
        }
        
        while(!maxH.empty() && k--){
            int maxFreq = maxH.top();
            // reduce the topmost frequency by 1
            maxFreq--;
            maxH.pop();
            if(maxFreq > 0){
                // if the reduced frequency still greater than 1, then push
                // the new frequency of the character onto the stack
                maxH.push(maxFreq);
            }
        }
        
        
        
        int sum = 0;
        while(!maxH.empty()){
            int maxFreq = maxH.top();
            sum += maxFreq * maxFreq;
            maxH.pop();
        }
        
        return sum;
    }
};

// Time Complexity:
// O(n)          -> counting character frequencies
// O(m log m)    -> building max-heap (m = number of unique characters)
// O(k log m)    -> k removals from heap
// Overall: O(n + k) since m ≤ 26

// Space Complexity:
// O(m) -> heap + frequency map (effectively constant)