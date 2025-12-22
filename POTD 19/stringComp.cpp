class Solution {
public:
    string compressedString(string word) {
        int cnt = 1;
        char letter = word[0];
        string comp = "";
        // Reserving possible max. memory for the "comp" string 
        comp.reserve(word.size()*2);

        for(int i=1; i<word.size(); i++){
            if(letter != word[i] || (cnt == 9)){
                // if new letter come up or the letter count is now greater than 9
                comp.push_back('0' + cnt);
                comp.push_back(letter);
                letter = word[i];
                cnt = 1;
            }
            else{
                cnt++;  
            }
        }

        // push the last letter with the count
        comp.push_back('0' + cnt);
        comp.push_back(letter);

        return comp;
    }
};

// TC: O(n) — single traversal of the string
// SC: O(n) — output string can grow up to 2n characters in the worst case