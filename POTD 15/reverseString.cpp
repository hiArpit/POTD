class Solution {
public:
    string reverseVowels(string s) {
        // Sliding window
        int i = 0;
        int j = s.length()-1;

        while(i<j){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                if(s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' || s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }

        return s;
        
    }
};
// TC:- O(n) why?? because each character is visited at most once by either pointer.
// SC:- O(1) why?? we are not using any extra space