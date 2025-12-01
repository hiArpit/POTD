class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int sum = 0;
        for(auto op: operations){
            // traverse through operations
            if(op == "C"){
                // check if it is "C" means last element will be popped off
                sum -= score.back();
                score.pop_back();
            }
            else if(op == "D"){
                // if it is "D", last element will be doubled up
                int num = score.back();
                sum += num * 2;
                score.emplace_back(num * 2);
            }
            else if(op == "+"){
                // If it is "+", then the last two elements will be added up.
                int first = score.back();
                int second = score[score.size() - 2];
                int result = first + second;
                sum += result;
                score.emplace_back(result);
            }
            else{
                // now, if it is a normal integer inside string then it will be typecasted to integer first, then inserted into the score.
                int num = stoi(op);
                sum += num;
                score.emplace_back(num);
            }
        }
        return sum;
    }
};

// Time complexity:- O(n) for traversing through the vector of size n to compute final score and maintain score vector
// Space complexity:- O(n) for maintaing a score vector in order to compute score