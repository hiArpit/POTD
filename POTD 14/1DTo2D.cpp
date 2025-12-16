class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n){
            return {};
        }

        // Pre-size the 2D vector in advance to avoid extra push-back
        vector<vector<int>> matrix(m, vector<int>(n));
        // matrix of size m row and each row having the size of n columns
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = original[cnt];
                cnt++;
            }
        }

        return matrix;
    }
};

// TC:- O(m*n) why?? as we are traversing for each m rows and n columns
// SC:- O(1) in context for auxiliary why?? we are not using any extra space for the output. O(m*n) for storing the output matrix