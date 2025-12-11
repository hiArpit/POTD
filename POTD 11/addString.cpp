class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.length() - 1;
        int end2 = num2.length() - 1;
        // pointer to the end of the string to point to the last digit
        // to calculate the sum
        string result;
        // resultant string
        int carry = 0;
        while(end1 >= 0 || end2 >= 0 || carry){
            int dig1 = (end1>=0) ? num1[end1--] - '0': 0;
            // if end1 is greater than 0, then access the index otherewise set to 0
            // simultaniously making the pointer to move to the left
            // - '0' for getting integer form
            int dig2 = (end2>=0) ? num2[end2--] - '0': 0;
            int digSum = dig1 + dig2 + carry;
            carry = digSum/10;
            // to get the carry
            result.push_back((digSum%10) + '0');
            // + '0' to get the integer into character form
        } 
        reverse(result.begin(), result.end());
        // reversing the resultant string, as it contains the sum in reverse order


        return result;
    }
};

// TC:- O(n) why?? if the largest string has n characters. We are traversing through each string together
// SC:- O(n) why?? we are using extra space to store result string