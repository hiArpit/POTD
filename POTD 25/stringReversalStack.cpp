class Solution {
  public:
    string reverse(const string& S) {
        // code here
        stack<char> reverse_s;
        
        for(char ch: S){
            reverse_s.push(ch);
        }
        
        string reverse_res = "";
        reverse_res.reserve(S.size());
        while(!reverse_s.empty()){
            reverse_res.push_back(reverse_s.top());
            reverse_s.pop();
        }
        
        return reverse_res;
    }
};

// O(n) why?? we are traversing through each and every character of the string
// O(n) why?? we are using stack of size n