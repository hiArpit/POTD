class KthLargest {
    priority_queue<int, vector<int>, greater<int>> largest;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums){
            largest.push(num);
            if(largest.size() > k){
                largest.pop();
            }
            // maintain the kth largest element at the top after the traversal
            // whenever the size of the minHeap "largest" goes beyond the k
            // pop the (k+1)th largest element
        }
    }
    
    int add(int val) {
        largest.push(val);
        if(largest.size() > k){
            largest.pop();
        }

        return largest.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Time Complexity:
// Constructor: O(n log k)  -> inserting n elements while maintaining heap size k
// add():        O(log k)    -> one push and at most one pop

// Space Complexity:
// O(k) -> min-heap stores only k elements