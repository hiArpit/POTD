class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> ropes;
        // building minHeap to track the smallest rope length at the top
        
        int n = arr.size();
        
        for(int num: arr){
            ropes.push(num);
        }
        
        int cost = 0;
        
        while(ropes.size() != 1){
            int first = ropes.top();
            ropes.pop();
            int second = ropes.top();
            ropes.pop();
            cost = cost + first + second;
            ropes.push(first+second);
            // now push the sum of the two smallest elements into the minHeap 
        }
        
        return cost;
    }
};

// Time Complexity: O(n log n)
//   - O(n log n) to build the heap
//   - O((n-1)log n) of while loop, as we are doing two pop and one push operations
// Space Complexity: O(n) to have n size of heap