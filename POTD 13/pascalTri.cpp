class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> formations(numRows);
        for(int i=0; i<numRows; i++){
            formations[i].resize((i+1), 1);
            for(int j=1; j<i; j++){
                formations[i][j] = formations[i-1][j-1] + formations[i-1][j];
            }
        }

        return formations;
    }
};

// TC:- O(n^2) why?? because we traverse each row and each column of increasing size
// SC:- O(n^2) why?? we are storing vector containing n row generated with each different n columns.