class Solution {
public:
    string reverseWords(string s) {
        string result;
        string temp;
        // Run the loop to build a string that doesn't have any unnecessary spaces
        for(char ch: s){
            if(ch == ' '){
                if(!temp.empty()){
                    if(!result.empty()){
                        result.push_back(' ');
                    }
                    result.append(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(ch);
            }
        }

        // To add the last word into the string 
        if(!temp.empty()){
            if(!result.empty()){
                result.push_back(' ');
            }
            result.append(temp);
        }

        // reversing the content of the string result e.g. hi hello ->olleh ih
        reverse(result.begin(), result.end());

        // Now, running the final loop to reverse the reversed string into words e.g. olleh ih -> hello hi 
        int i = 0;
        while(i < result.size()){
            int j = i;
            while(j < result.size() && result[j] != ' '){
                j++;
            }
            reverse(result.begin()+i, result.begin()+j);
            i = j+1;
        }

        return result;

    }

};

// TC:- O(n), we are running two linear loops, one for reversing the entire string and another for reversing the reverse string to make words
// SC:- O(n), we are using two string, one for maintaining a string(result) with no unnecessary space, and another(temp) for putting words into that string