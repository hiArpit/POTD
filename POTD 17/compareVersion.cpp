class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Brute 
        vector<string> first;
        vector<string> second;

        // Build the first vector of strings for version1
        string temp;
        for(char ch: version1){
            if(ch == '.'){
                if(!temp.empty()){
                    first.push_back(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(ch);
            }
        }
        if(!temp.empty()){
            first.push_back(temp);
            temp.clear();
        }

        // Build the vector of strings for version2
        for(char ch: version2){
            if(ch == '.'){
                if(!temp.empty()){
                    second.push_back(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(ch);
            }
        }
        if(!temp.empty()){
            second.push_back(temp);
            temp.clear();
        }

        int n1 = first.size();
        int n2 = second.size();

        // If any of the vector's size is small, then resize to have 0
        if(n1 < n2){
            first.resize(n2, "0");
        }

        if(n2 < n1){
            second.resize(n1, "0");
        }

        // Comparison one by one of each element of the both
        
        for(int k=0; k<first.size(); k++){
            int one = stoi(first[k]);
            int two = stoi(second[k]);
            if(one < two){
                return -1;
            }
            else if(two < one){
                return 1;
            }
        }

        return 0;
    }
};

// Time Complexity: O(L1 + L2)
// where L1 and L2 are the lengths of version1 and version2.
// We traverse each string once to split, and each digit is processed
// again during stoi conversion.

// Space Complexity: O(L1 + L2)
// Extra space is used to store the split version numbers.