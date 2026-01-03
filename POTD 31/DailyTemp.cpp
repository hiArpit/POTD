class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        // maintaining a stack in order to track the colder temperature
        int n = temperatures.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                // if the current temperature is greater than the temperature
                // at the top of the stack, then the pop that temperature's index
                int idx = temp.top();
                // find the gap between the days
                res[idx] = i-idx;
                temp.pop();
            }
            temp.push(i);
        }

        while(!temp.empty()){
            // Now, the remaining days at the stack don't get the warmer
            // temperatures in future days
            int idx = temp.top();
            res[idx] = 0;
            temp.pop();
        }

        return res;
    }
};

// TC:- O(n) for evaluating each day, the inner while loop's TC is constant
// as we are pushing and popping each element once
// SC:- O(n) in the worst case, if the days' temperatures are in descending order