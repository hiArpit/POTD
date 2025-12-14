class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Not understanding the pattern
        vector<int> result;
        int left = 0;
        int top = 0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;

        while((left <= right) && (top <= bottom)){
            // from left to right of top-row
            for(int i=left; i<=right; i++){
                result.push_back(matrix[top][i]);
            }
            // Moving to the next row
            top += 1;

            // Moving top to bottom of the last column
            for(int i=top; i<=bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right -= 1;

            if(!((left <= right) && (top <= bottom))) break;
            // Now moving right to left of the bottom row
            for(int i=right; i>=left; i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom -= 1;

            // Moving from bottom to top of the first column
            for(int i=bottom; i>=top; i--){
                result.push_back(matrix[i][left]);
            }
            left += 1;
        }

        return result;
    }
};

// TC:- O(m*n) why?? m represents no. of rows and n represents no. of columns
// and here, we are going through each and every element.
// First, we are running outer while loop, to get into each row and column in spiral format through inner for loops
// SC:- O(m*n) why?? we are using result vector of size m*n