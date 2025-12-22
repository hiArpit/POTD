class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // cnt stores total bottles drunk
        int cnt = numBottles;

        // Keep exchanging empty bottles while possible
        while (numBottles >= numExchange) {
            // New bottles obtained after exchange
            cnt += numBottles / numExchange;

            // Update empty bottles:
            // exchanged bottles + remaining bottles
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }

        return cnt;
    }
};

/*
Time Complexity: O(log n)
- In each iteration, numBottles is reduced by division with numExchange.
- Repeated division leads to logarithmic number of iterations.

Space Complexity: O(1)
- Only constant extra variables are used.
- No additional data structures are required.
*/