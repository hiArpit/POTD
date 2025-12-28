class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        unordered_map<char, int> freq;
        // Maintain a hash map to track the frequency of each letter
        queue<char> q;
        // create a queue as we are inserting the first non-repeating
        // character
        string res = "";
        
        for(char letter: s){
            freq[letter]++;
            // increment the occurence of each character
            q.push(letter);
            
            //
            while(!q.empty() && freq[q.front()] > 1){
                q.pop();
                // pop the character that have more than frequency of one
                // as long as the queue is not empty
            }
            
            if(q.empty()){
                res.push_back('#');
            }
            else{
                res.push_back(q.front());
            }
        }
        
        return res;
    }
};

// TC: O(n) why?? why?? n is the size of the string and
// Each character is pushed and popped from the queue at most once.
// Hence total operations over the whole loop are linear.
// SC: O(1)
// Frequency map stores at most 26 characters.
// Queue stores characters from a fixed alphabet.
// Space does not grow with input size.