class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;        // Index of the minimum price so far (buy day)
        int maxi = 0;     // Stores the maximum profit achievable
        
        // Iterate through prices starting from day 1 as day 0 is the initial buy candidate
        for(int i = 1; i < prices.size(); i++){
            
            // If a lower price is found, update the buy day
            if(prices[i] < prices[l]){
                l = i;
            }
            else{
                // Calculate profit by selling on the current day
                int cost = prices[i] - prices[l];
                
                // Update maximum profit if current profit is higher
                maxi = max(cost, maxi);
            }
        }

        return maxi; // Return the maximum profit
    }
};

/*
Time Complexity: O(n)
- We traverse the price array once

Space Complexity: O(1)
- Only a few variables are used; no extra space.
*/