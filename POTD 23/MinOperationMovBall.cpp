class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size());
        int balls = 0, cost = 0;
        // prefix balls sum
        for(int i=0; i<boxes.size(); i++){
            result[i] = cost;
            if(boxes[i] == '1'){
                balls++;
            }
            cost += balls;
        }

        // Postfix balls sum
        balls = 0, cost = 0;
        for(int i=boxes.size()-1; i>=0; i--){
            result[i] += cost;
            if(boxes[i] == '1'){
                balls++;
            }
            cost += balls;
        }

        return result;
    }
};

// TC:- O(n) why?? we are running two linear loop, one for prefix balls sum and another for postfix balls sum
// SC:- O(n) why?? we are using result vector size of n 