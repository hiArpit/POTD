class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxGifts;
        // creating maxHeap to get the maximum gifts in a pile at the top
        for(int gift: gifts){
            maxGifts.push(gift);
        }

        for(int i=0; i<k; i++){
            int maxGift = maxGifts.top();
            maxGifts.pop();
            int reduce = floor(sqrt(maxGift));
            // replacement
            maxGifts.push(reduce);
        }

        long long sum = 0;
        while(!maxGifts.empty()){
            sum += maxGifts.top();
            maxGifts.pop();
        }

        return sum;
    }
};

// Time Complexity: O((n + k) log n), nlogn is the TC to push elements into the maxHeap, klogn is the TC after each second we make changes into the maxheap that takes logn time
// Space Complexity: O(n)