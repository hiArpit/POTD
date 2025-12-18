class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Creating an unordered map to store and organise strings based on sorted string used as key
        unordered_map<string, vector<string>> sort_str;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            // if(sort_str.find(temp) != sort_str.end()){
            //     sort_str[temp].append(i);
            // }
            // else{
            //     sort_str[temp].append(i);
            // }
            // Unnecessary
            sort_str[temp].push_back(strs[i]);
        }

        vector<vector<string>> result(sort_str.size());
        int idx = 0;
        for(auto it: sort_str){
            result[idx] = it.second;
            idx++;
        }

        // Building the resultant string to group the anagrams together through sort_str unordered map.

        return result;
    }
};

// Time Complexity: O(n * k log k)
// where n is the number of strings and k is the average length of a string.
// Each string is sorted individually, O(klogk) is the time taken to sort each string

// Space Complexity: O(n * k)
// Extra space is used for the unordered_map keys (sorted strings)
// and for storing all strings in grouped form.