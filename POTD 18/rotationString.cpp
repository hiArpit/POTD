class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string result = s1 + s1;
        return (result.find(s2) != string::npos);
    }
};

// Time Complexity: O(n²) in the worst case,
// where n is the length of the string.
// This is due to substring search using string::find().

// Space Complexity: O(n),
// extra space used to store the concatenated string s1 + s1.